// Created by Susanka on 05/11/2019.

#include "zadanie2.h"

clock_t start_timer(){
    return clock();
}

clock_t end_timer(){
    return clock();
}

void test1(){
    clock_t start, end;
    double total;
    int lower = 5, upper = 100000;

    start = start_timer();
    struct Node* tree = NULL;

    for(int i = 0; i < 50000; i++){
        int number = (rand() % (upper - lower + 1)) + lower;
        insert(tree, number);
    }

    //printf("Hodnota 30 = %d\n", search(tree, 30)->key);
    print_in_orderAVL(tree);
    //print2DAVL(tree);
    end = end_timer();

    total = (double)(end - start);
    printf("Celkovy cas vykonania = %f ms\n", total);
}

void test2(){
    //test splay 50 000
    clock_t start, end;
    double total;

    start = start_timer();
    ELEMENT* tree = NULL;
    int lower = 5, upper = 100000;

    for(int i = 0; i < 50000; i++){
        int number = (rand() % (upper - lower + 1)) + lower;
        tree = add_element(number, tree);
    }

    print_in_order(tree);
    //print2D(tree);
    end = end_timer();

    total = (double)(end - start);
    printf("\n\nCelkovy cas vykonania = %f ms\n", total);
}

void test3(){
    //prisposobbenie tabulky, ak sa vela nahromadi
    HASH_TABLE* table_wrapper = create_hash_table(5);
    table_wrapper = add_to_table("ahoj", 5, table_wrapper);
    table_wrapper = add_to_table("joha", 5, table_wrapper);
    table_wrapper = add_to_table("joha", 5, table_wrapper);
    table_wrapper = add_to_table("ojah", 5, table_wrapper);
    table_wrapper = add_to_table("joha", 5, table_wrapper);
    table_wrapper = add_to_table("zakladac", 9, table_wrapper);
    table_wrapper = add_to_table("random_slovo", 13, table_wrapper);
    table_wrapper = add_to_table("milujem tento predmet", 22, table_wrapper);
    table_wrapper = add_to_table("random_slovo_este_dlhsie_to_je", 31, table_wrapper);
    table_wrapper = add_to_table("nieco pekne :)", 15, table_wrapper);
    table_wrapper = add_to_table("vkladam ine slovo", 18, table_wrapper);
    table_wrapper = add_to_table("smajlikyyyy O:)", 16, table_wrapper);
    display_table(table_wrapper);

    display_if_found("ojah", 5, table_wrapper);
}

void test4(){
    //resize na mensiu/vacsiu hodnotu, ktoru chcem
    HASH_TABLE* table_wrapper = create_hash_table(20);
    table_wrapper = add_to_table("ahoj", 5, table_wrapper);
    table_wrapper = add_to_table("joha", 5, table_wrapper);
    table_wrapper = add_to_table("zkalacad", 9, table_wrapper);
    table_wrapper = add_to_table("joha", 5, table_wrapper);
    table_wrapper = add_to_table("ojah", 5, table_wrapper);
    table_wrapper = add_to_table("zakladac", 9, table_wrapper);
    table_wrapper = add_to_table("random_slovo", 13, table_wrapper);
    table_wrapper = add_to_table("milujem tento predmet", 22, table_wrapper);
    table_wrapper = add_to_table("random_slovo_este_dlhsie_to_je", 31, table_wrapper);
    display_table(table_wrapper);

    display_if_found("ojah", 5, table_wrapper);
    table_wrapper = resize_table(table_wrapper, 15);
    printf("---------------------------------------------------\n");
    display_table(table_wrapper);
}

void test5(){
    //prisposobbenie tabulky, ak sa vela nahromadi
    HASH_TABLE* table_wrapper = create_hash_table(5);
    table_wrapper = add_to_table("cervenalampa", 13, table_wrapper);
    table_wrapper = add_to_table("cervenalamap", 13, table_wrapper);
    table_wrapper = add_to_table("ecrvenalampa", 13, table_wrapper);
    table_wrapper = add_to_table("cevrenalampa", 13, table_wrapper);
    table_wrapper = add_to_table("cervenlaampa", 13, table_wrapper);
    table_wrapper = add_to_table("crevenalampa", 13, table_wrapper);
    table_wrapper = add_to_table("cervenamalpa", 13, table_wrapper);
    table_wrapper = add_to_table("aervenalampc", 13, table_wrapper);
    table_wrapper = add_to_table("vercenalampa", 13, table_wrapper);
    display_table(table_wrapper);
}

void test6(){
    Insert(10);
    Insert(87);
    Insert(76);
    Insert(23);
    Insert(176);
    Insert(134);
    Insert(543);
    Insert(74);
    Insert(99);
    PrintList();
}

void test7(){
    clock_t start, end;
    double total;

    start = start_timer();
    ELEMENT* tree = NULL;
    ELEMENT* element;

    add_value(10, &tree);
    add_value(15, &tree);
    add_value(25, &tree);
    add_value(30, &tree);
    add_value(1, &tree);
    add_value(9, &tree);
    add_value(6, &tree);
    add_value(5, &tree);
    add_value(49, &tree);

    search_value(tree, 79);

    print_in_order(tree);
    print2D(tree);
    end = end_timer();

    total = (double)(end - start);
    printf("Celkovy cas vykonania = %f ms\n", total);
}

void test8(){
    //
}