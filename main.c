#include<stdio.h>
#include"types.h"
#include"validate.h"
#include"operations.h"
#include"create.h"
#include"stdlib.h"


int  main(int argc,char **argv)
{
    LIST *head;
    HASH_T H_table[28];
    
    if(readAndValidate(argc,argv,&head)==SUCCESS)
    {
        printf("[INFO]: File in the list are : ");
        printList(head);
    }
    while(1)
    {
        displayMenu();

        int choice;
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                createDatabase(H_table,&head);
                break;
            case 2:
                displayDatabase(H_table);
                break;

            case 3:

            case 4:

            case 5:

            default:
                exit(0);

        }

    }

}