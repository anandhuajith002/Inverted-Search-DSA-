#include<stdio.h>
#include"types.h"
#include"validate.h"
#include"operations.h"
#include"create.h"
#include<stdlib.h>
#include"display_search.h"
#include"save_update.h"

int  main(int argc,char **argv)
{
    LIST *head;
    HASH_T H_table[28];
    int createflag=0;
    
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
                if(createflag!=0)
                {
                    printf("[INFO]: Databse already created\n");
                    break;
                }
                createDatabase(H_table,&head);
                createflag=1;
                break;

            case 2:
                displayDatabase(H_table);
                break;

            case 3:
                char word[20];
                printf("[INFO]:Enter the word to be searched : ");
                scanf("%s",word);
                searchDatabase(H_table,word);
                break;

            case 4:
                saveDatabase(H_table);
                break;

            case 5:
                if(createflag!=0 )
                {
                    printf("[INFO]: Database already creatded . Update not possible\n");
                    break;
                }
                updateDatabase(H_table,&head);
                break;

            case 6:
                exit(0);
                
            default:
                printf("[INFO]:Invalid choice\n");
        }

    }

}