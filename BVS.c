// Created by Susanka on 28/10/2019.

#include "zadanie2.h"

ELEMENT *create_element_bvs(int value) {
    ELEMENT *new_tree = (ELEMENT *) malloc(sizeof(ELEMENT));

    new_tree->value = value;
    new_tree->smaller = NULL;
    new_tree->bigger = NULL;

    return new_tree;
}

void add_value(int value, ELEMENT** tree){
    ELEMENT* adding_element = create_element_bvs(value);
    ELEMENT** aktual = tree;

    if(is_tree_empty(*tree)){
        *aktual = adding_element;
        return;
    }

    if(is_in_smaller_tree(*tree, value)){
        //rekurzivne volanie

        aktual = &((*tree)->smaller);
        add_value(value,  aktual);
    }

    else if(is_in_bigger_tree(*tree, value)){
        //rekurzivne volanie

        aktual = &((*tree)->bigger);
        add_value(value,  aktual);
    }
}

ELEMENT *search_value(ELEMENT *tree, int value) {
    if(tree == NULL){
        printf("Nenachadza sa v strome\n");
        return NULL;
    }

    if(value == tree->value){
        return tree;
    }

    else if(value < tree->value){
        return search_value(tree->smaller, value);
    }

    else if(value >= tree->value){
        return search_value(tree->bigger, value);
    }
}