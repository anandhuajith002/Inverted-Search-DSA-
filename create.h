
#ifndef CREATE_H
#define CREATE_H

#include"types.h"


//function in main to create database
Status createDatabase(HASH_T *H_table,LIST **head);

//initialise index and link to null
Status initialiseHTable(HASH_T *H_table);

//sub function to create database
Status createHashTable(HASH_T *H_table,LIST **head);

//traverse esch file and inser word to table
Status traverseFile(char *filename,FILE *fptr,HASH_T *h_table);

Status addToHashT(int index,char *str,char *filename,HASH_T *H_table);


MAIN_NODE* createMainNode(char *str);


Status addToSubNode(MAIN_NODE* mainNode,char *filename);

void displayDatabase(HASH_T *H_table);

#endif