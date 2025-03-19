#ifndef TYPES_H
#define TYPES_H

#include<stdio.h>

typedef enum{
    SUCCESS,
    FAILURE,
    FILENOTFOUND,
    DUPLICATE,
    EMPTY,
}Status;

typedef struct node
{
    char filename[15];
    FILE *fptr;
    struct node * link;

}LIST;

typedef struct subnode
{
    int wordcount;
    char filename[15];
    struct subnode *link;

}SUB_NODE;

typedef struct mainnode
{
    int filecount;
    char word[50];
    struct mainnode *mainlink;
    struct subnode * sublink;
}MAIN_NODE;


typedef struct hash
{
    int index;
    struct mainnode * link;
}HASH_T;


#endif // !TYPES_H