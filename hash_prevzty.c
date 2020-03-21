// Created by Susanka on 05/11/2019.

//kod prevzdaty z: https://github.com/prabaprakash/Data-Structures-and-Algorithms-Programs/blob/master/Hashing%20-%20Linear%20Probing%20(Open%20addressing).c

#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int arr[SIZE]={};
int count;

int CalculateHash(int key)
{
    return key%SIZE;
}

void Insert(int element)
{
    if(count==SIZE){
        printf("Error.\nTable if FULL\n");
        exit(EXIT_FAILURE);
    }
    int probe=CalculateHash(element);
    while(arr[probe]!=NULL && arr[probe]!=-1)
    {
        probe=(probe+1)%SIZE;
    }
    arr[probe]=element;
    count++;
}

void Delete(int element)
{
    if(count==0){
        printf("Error.\nTable if EMPTY\n");
        exit(EXIT_FAILURE);
    }
    int loc=Search(element);
    if(loc!=-1)
    {
        arr[loc]=-1;
        count--;
    }
}

int Search(int element)
{
    if(count==0){
        printf("Error.\nTable if EMPTY\n");
        exit(EXIT_FAILURE);
    }
    int probe=CalculateHash(element);
    while(arr[probe]!=0)
    {
        if(arr[probe]==element)
            return probe;
        probe=(probe+1)%SIZE;
    }
    printf("\nElement %d not found.\n",element);
    return -1;
}

void PrintList()
{
    int i;
    for(i=0;i<SIZE;i++)
        printf("%d%c",arr[i],' ');
}