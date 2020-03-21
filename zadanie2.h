// Created by Susanka on 01/11/2019.

#ifndef DSA_2_ZADANIE_SPLAY_ALTERNATIVNY_HEADER_H
#define DSA_2_ZADANIE_SPLAY_ALTERNATIVNY_HEADER_H
#endif //DSA_2_ZADANIE_SPLAY_ALTERNATIVNY_HEADER_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<limits.h>

#define COUNT 10
#define PRIME 811

// An AVL tree node
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

typedef struct element {
    int value;
    struct element *smaller;
    struct element *bigger;
    struct element *parent_root;
} ELEMENT;

typedef struct hash_table_element {
    char *data;
    int data_size;
    int number_of_next;
    struct hash_table_element *next;
} HASH_TABLE_ELEMENT;

typedef struct hash_table {
    HASH_TABLE_ELEMENT **table;
    int size;
} HASH_TABLE;

//from BVS.c
ELEMENT *create_element_bvs(int value);

void add_value(int value, ELEMENT **tree);

ELEMENT *search_value(ELEMENT *tree, int value);

void remove_element(ELEMENT *tree, int value);

//from printing_info.c
void print2DUtil(ELEMENT *root, int space);

void print2D(ELEMENT *root);

void print_in_order(ELEMENT *element);

void print2DAVL(struct Node *root);

void print2DUtilAVL(struct Node *root, int space);

void print_in_orderAVL(struct Node *element);

//from conditions.c
int is_tree_empty(ELEMENT *tree);

int is_in_smaller_tree(ELEMENT *root, int value);

int is_in_bigger_tree(ELEMENT *root, int value);

int am_i_root(ELEMENT *me);

//from splay_tree.c
ELEMENT *create_element(int value);

ELEMENT *create_bigger(ELEMENT *new_root, int value);

ELEMENT *create_smaller(ELEMENT *new_root, int value);

ELEMENT *right_rotation(ELEMENT *previous_root);

ELEMENT *left_rotation(ELEMENT *previous_root);

ELEMENT *splay_to_root(ELEMENT *previous_root);

ELEMENT *add_element(int value, ELEMENT *previous_root);

ELEMENT *find_value(int value, ELEMENT *root);

//from AVL-prevzate.c
int maximum(int a, int b);

int height(struct Node *N);

struct Node *newNode(int key);

struct Node *rightRotate(struct Node *y);

struct Node *leftRotate(struct Node *x);

int getBalance(struct Node *N);

struct Node *insert(struct Node *node, int key);

struct Node *search(struct Node *root, int key);

//from hash_function.c
int hash(char *string, int length, int hash_table_size);

HASH_TABLE_ELEMENT *create_next_element();

HASH_TABLE *create_hash_table(int size);

HASH_TABLE_ELEMENT* create_table_row();

HASH_TABLE *add_to_table(char *string, int length, HASH_TABLE *table_wrapper);

HASH_TABLE_ELEMENT *find_in_table(char *string, int length, HASH_TABLE *table_wrapper);

HASH_TABLE *resize_table(HASH_TABLE *table_wrapper, int new_size);

//from display_hash_table.c
void display_table(HASH_TABLE *table_wrapper);

void display_if_found(char *string, int length, HASH_TABLE *table_wrapper);

//from hash_prevzaty.c

int CalculateHash(int key);
void Insert(int element);
void Delete(int element);
int Search(int element);
void PrintList();

//from testing.c
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();