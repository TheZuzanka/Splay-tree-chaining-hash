// Created by Susanka on 01/11/2019.

#include "zadanie2.h"

int is_tree_empty(ELEMENT* tree){
    if(tree == NULL){
        return 1;
    }
    else{
        return  0;
    }
}

int is_in_smaller_tree(ELEMENT* root, int value){
    if(root->value > value){
        return 1;
    }
    else{
        return 0;
    }
}

int is_in_bigger_tree(ELEMENT* root, int value){
    if(root->value <= value){
        return 1;
    }
    else{
        return 0;
    }
}

int am_i_root(ELEMENT* me){
    if(me->parent_root == NULL){
        return 1;
    }
    else{
        return 0;
    }
}