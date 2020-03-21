// Created by Susanka on 02/11/2019.

#include "zadanie2.h"

void display_table(HASH_TABLE* table_wrapper){
    HASH_TABLE_ELEMENT** table = table_wrapper->table;
    int number_of_elements = 0;

    for(int i = 0; i < table_wrapper->size; i++){
        HASH_TABLE_ELEMENT* aktual = table[i];

        if(table[i] == NULL){
            number_of_elements = 0;
        }
        else{
            number_of_elements = table[i]->number_of_next;
        }

        printf("Index = %3d | Prvky v riadku = %3d |", i, number_of_elements);

        while(aktual != NULL){
            printf("%s|", aktual->data);
            aktual = aktual->next;
        }
        printf("\n");
    }
}

void display_if_found(char* string, int length, HASH_TABLE* table_wrapper){
    HASH_TABLE_ELEMENT* element;

    if((element = find_in_table(string, length, table_wrapper)) != NULL){
        int my_hash = hash(string,length,table_wrapper->size);
        printf("Pozicia %s v tabulke je %d.\n", element->data, my_hash);
    }
    else{
        printf("Dany element sa v tabulke nenachadza\n");
    }
}