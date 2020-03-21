// Created by Susanka on 01/11/2019.
#include "zadanie2.h"

#define COUNT 10

void print2DUtil(ELEMENT *root, int space) {
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->bigger, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);

    print2DUtil(root->smaller, space);
}

void print2D(ELEMENT *root) {
    print2DUtil(root, 0);
}

void print_in_order(ELEMENT *element) {
    if (element != NULL){
        print_in_order(element->smaller);
        printf("%d ", element->value);
        print_in_order(element->bigger);
    }
}

void print2DUtilAVL(struct Node *root, int space) {
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtilAVL(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    print2DUtilAVL(root->left, space);
}

void print2DAVL(struct Node *root) {
    print2DUtilAVL(root, 0);
}

void print_in_orderAVL(struct Node *element) {
    if (element != NULL){
        print_in_orderAVL(element->left);
        printf("%d ", element->key);
        print_in_orderAVL(element->right);
    }
}