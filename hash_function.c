// Created by Susanka on 01/11/2019.

#include "zadanie2.h"

int hash(char* string, int length, int hash_table_size){
    int hash = 0, i;
    for(i = 0; i < length; i++){
        //printf("%c[%d] = %d\n", string[i], i, (int)string[i] + i);
        hash += ((int)string[i] + (i * PRIME + string[0]));
    }

    hash = hash % hash_table_size;
    return hash;
}

HASH_TABLE* create_hash_table(int size){
    HASH_TABLE* table_wrapper = (HASH_TABLE*)malloc(sizeof(HASH_TABLE));
    table_wrapper->size = size;
    table_wrapper->table = (HASH_TABLE_ELEMENT**)malloc(size * sizeof(HASH_TABLE_ELEMENT*));

    HASH_TABLE_ELEMENT** table = table_wrapper->table;

    for(int i = 0; i < size; i++){
        table[i] = NULL;
    }

    return table_wrapper;
}

HASH_TABLE_ELEMENT* create_table_row(){
    HASH_TABLE_ELEMENT* element = (HASH_TABLE_ELEMENT*)malloc(sizeof(HASH_TABLE_ELEMENT));
    element->number_of_next = 0;
    element->data_size = 0;
    element->data = NULL;
    element->next = NULL;

    return element;
}

HASH_TABLE_ELEMENT* create_table_element(){
    HASH_TABLE_ELEMENT* element = (HASH_TABLE_ELEMENT*)malloc(sizeof(HASH_TABLE_ELEMENT));
    element->number_of_next = 0;
    element->data_size = 0;
    element->data = NULL;
    element->next = NULL;

    return element;
}

HASH_TABLE* add_to_table(char* string, int length, HASH_TABLE* table_wrapper){
    int index = hash(string, length, table_wrapper->size);
    HASH_TABLE_ELEMENT** table = table_wrapper->table;

    if(index >= table_wrapper->size){
        printf("Hashovacia tabulka je prilis mala.\n");
        return table_wrapper;
    }

    if(table[index] == NULL){
        //som prazdny
        table[index] = create_table_row();
        table[index]->data = (char*)malloc(length * sizeof(char));
        strcpy(table[index]->data, string);
        table[index]->data_size = length;
        table[index]->number_of_next = 1;
        free(string);

        return table_wrapper;
    }
    else{
        //mam nejaky prvok v linked liste
        HASH_TABLE_ELEMENT* aktual = table[index];

        //check ci tam toto slovo nie je
        if(strcmp(string, aktual->data) == 0){
            return table_wrapper;
        }

        while(aktual->next != NULL){
            aktual = aktual->next;
            //posuniem sa na koniec
        }

        aktual->next = create_table_element();
        aktual = aktual->next;

        (table[index]->number_of_next)++;
        aktual->data = (char*)malloc(length * sizeof(char));
        strcpy(aktual->data, string);
        aktual->data_size = length;
        free(string);

        //printf("slovo = %s\n", string);
        if(table[index]->number_of_next > 3){
            //nastavenim na jedna je sranda. :)

            if (table_wrapper->size *2 > INT_MAX - 100){
                //ach..
                printf("Nie je mozne alokovat vacsiu tabulku");
                return table_wrapper;
            }
            table_wrapper = resize_table(table_wrapper, (table_wrapper->size)*2);
        }
        return table_wrapper;
    }
}

HASH_TABLE_ELEMENT* find_in_table(char* string, int length, HASH_TABLE* table_wrapper){
    HASH_TABLE_ELEMENT** table = table_wrapper->table;
    int my_hash = hash(string, length, table_wrapper->size);

    HASH_TABLE_ELEMENT* aktual = table[my_hash];

    while(aktual != NULL){
        if(strcmp(string, aktual->data) == 0){
            return aktual;
        }
        else{
            aktual = aktual->next;
        }
    }

    return NULL;
}

HASH_TABLE* resize_table(HASH_TABLE* table_wrapper, int new_size){
    HASH_TABLE* resized_table_wrapper = create_hash_table(new_size);

    HASH_TABLE_ELEMENT **table = table_wrapper->table;

    HASH_TABLE_ELEMENT* aktual;

    for(int i = 0; i < table_wrapper->size; i++){
        //printf("cyklus  = %d\n", i);
        if(table[i] != NULL){
            aktual = table[i];
            while(aktual != NULL){
                //printf("pridavam = %s\n", aktual->data);
                resized_table_wrapper = add_to_table(aktual->data, aktual->data_size, resized_table_wrapper);

                aktual = aktual->next;
            }
        }
    }

    //TODO uvolnit staru tabulku
    free(table_wrapper);

    return resized_table_wrapper;
}