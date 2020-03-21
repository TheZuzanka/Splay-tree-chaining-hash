cmake_minimum_required(VERSION 3.9)
project(DSA_2_zadanie_splay_alternativny C)

set(CMAKE_C_STANDARD 99)

add_executable(DSA_2_zadanie_splay_alternativny main.c zadanie2.h conditions.c printing_info.c splay_tree.c BVS.c AVL_prevzaty.c hash_function.c display_hash_table.c hash_prevzty.c testing.c)