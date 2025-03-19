#include"types.h"


//for printing the list
Status printList(LIST *head);

//add filename and fptr to list
Status addToList(LIST **head,char *filename,FILE *fptr);

//check for duplicate in list
Status noDuplicate(LIST *head,char *filename);

void displayMenu();