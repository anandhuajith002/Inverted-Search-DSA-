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



#endif // !TYPES_H