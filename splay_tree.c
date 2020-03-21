// Created by Susanka on 01/11/2019.
#include "zadanie2.h"

ELEMENT *create_element(int value){
    ELEMENT* root = (ELEMENT *) malloc(sizeof(ELEMENT));
    root->smaller = NULL;
    root->bigger = NULL;
    root->parent_root = NULL;
    root->value = value;
    return root;
}

ELEMENT *create_bigger(ELEMENT* new_root, int value){
    new_root->bigger = create_element(value);
    new_root->bigger->parent_root = new_root;
    return new_root->bigger;
}

ELEMENT *create_smaller(ELEMENT* new_root, int value){
    new_root->smaller = create_element(value);
    new_root->smaller->parent_root = new_root;
    return new_root->smaller;
}

ELEMENT *right_rotation(ELEMENT *previous_root) {
    ELEMENT *smaller = previous_root->smaller;
    ELEMENT *parent = previous_root->parent_root;
    ELEMENT *bigger_smaller = smaller->bigger;

    if (!is_tree_empty(parent)) {
        if (parent->bigger == previous_root) parent->bigger = smaller;
        else parent->smaller = smaller;
    }
    if (bigger_smaller) {
        bigger_smaller->parent_root = previous_root;
    }
    smaller->parent_root = parent;
    smaller->bigger = previous_root;

    previous_root->parent_root = smaller;
    previous_root->smaller = bigger_smaller;

    return previous_root;
}

ELEMENT *left_rotation(ELEMENT *previous_root) {
    ELEMENT *bigger = previous_root->bigger;
    ELEMENT *parent = previous_root->parent_root;
    ELEMENT *bigger_smaller = bigger->smaller;

    if (parent) {
        if (parent->bigger == previous_root) parent->bigger = bigger;
        else parent->smaller = bigger;
    }
    if (bigger_smaller) {
        bigger_smaller->parent_root = previous_root;
    }
    bigger->parent_root = parent;
    bigger->smaller = previous_root;

    previous_root->parent_root = bigger;
    previous_root->bigger = bigger_smaller;

    return previous_root;
}

ELEMENT *splay_to_root(ELEMENT *previous_root) {
    while (1) {
        ELEMENT *my_parent = previous_root->parent_root;
        ELEMENT *my_parent_parent;

        if (am_i_root(previous_root)){
            break;
        }

        my_parent_parent = my_parent->parent_root;

        if (my_parent_parent == NULL) {
            //10-20 -> mam jedneho rodica, ktory je koren

            if (my_parent->smaller == previous_root){
                right_rotation(my_parent);
                break;
            }
            else{
                left_rotation(my_parent);
                break;
            }

        }
        if (my_parent_parent->smaller == my_parent) {
            //smaller podstrom

            if (my_parent->smaller == previous_root) {
                //smaller smaller
                right_rotation(my_parent_parent);
                right_rotation(my_parent);
            } else {
                //smaller bigger
                left_rotation(my_parent);
                right_rotation(my_parent_parent);
            }
        } else {
            //bigger podstrom

            if (my_parent->smaller == previous_root) {
                //bigger smaller
                right_rotation(my_parent);
                left_rotation(my_parent_parent);
            } else {
                //bigger bigger
                left_rotation(my_parent_parent);
                left_rotation(my_parent);
            }
        }
    }
    return previous_root;
}

ELEMENT *add_element(int value, ELEMENT *previous_root) {
    ELEMENT *new_root = previous_root;

    if (is_tree_empty(previous_root)) {
        return create_element(value);
    }
    while (new_root->value != value) {
        /*if (new_root->value == value){
            break;
            povodne bolo while(1)
        }*/
        if(value >= new_root->value){
            if (new_root->bigger != NULL){
                new_root = new_root->bigger;
            }
            else {
                new_root = create_bigger(new_root, value);
                break;
            }
        }
        else {
            //if value < new_root->value
            if (new_root->smaller != NULL){
                new_root = new_root->smaller;
            }
            else {
                new_root = create_smaller(new_root, value);
                break;
            }
        }
    }

    new_root = splay_to_root(new_root);
    return new_root;
}

ELEMENT *find_value(int value, ELEMENT *root) {
    ELEMENT* temp = root;

    if (is_tree_empty(root)) {
        return NULL;
    }

    while (root != NULL) {
        if (root->value == value) {
            break;
        }
        if (value >= (root->value)) {
            if (root->bigger != NULL) {
                root = root->bigger;
            } else {
                break;
            }
        } else {
            if (root->smaller != NULL) {
                root = root->smaller;
            } else {
                break;
            }
        }
    }

    root = splay_to_root(root);
    if (root->value == value) {
        return root;
    } else {
        printf("%d sa nenachadza v strome.\n", value);
        return temp;
    }
}