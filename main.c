#include<stdio.h>
#include"types.h"
#include"validate.h"
#include"operations.h"



int  main(int argc,char **argv)
{
    LIST *head=NULL;

    if(readAndValidate(argc,argv,&head)==SUCCESS)
    {
        printf("[INFO]: File in the list are : ");
        printList(head);
    }

}