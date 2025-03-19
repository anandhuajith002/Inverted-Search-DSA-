#include<stdio.h>
#include"types.h"
#include<ctype.h>
#include<stdlib.h>
#include<string.h>


int findIndex(char *word)
{
    char c=word[0];
    c=tolower(c);
    return c%97;
}
Status initialiseHTable(HASH_T *H_table)
{
    for(int i=0;i<28;i++)
    {
        H_table[i].index=i;
        H_table[i].link=NULL;
    }
}
Status addToSubNode(MAIN_NODE* mainNode,char *filename)
{
    
    SUB_NODE* temp=mainNode->sublink;
    SUB_NODE* prev=NULL;
    
    
    if(temp==NULL)
    {
        SUB_NODE *new=malloc(sizeof(SUB_NODE));
        if(new==NULL)
        {
            return FAILURE;
        }
        new->wordcount=1;
        strcpy(new->filename,filename);
        new->link=NULL;

        mainNode->sublink=new;
        return SUCCESS;
    }
    while(temp!=NULL)
    {
        if(strcmp(filename,temp->filename)==0)
        {
            temp->wordcount++;
            return SUCCESS;
        }
        
        prev=temp;
        temp=temp->link;
    }

    SUB_NODE *new=malloc(sizeof(SUB_NODE));
    if(new==NULL)
    {
        return FAILURE;
    }
    prev->link=new;
    new->wordcount=1;
    mainNode->filecount++;
    strcpy(new->filename,filename);
    new->link=NULL;    
    return SUCCESS;
    
}
MAIN_NODE* createMainNode(char *str)
{
    MAIN_NODE *new=malloc(sizeof(MAIN_NODE));
    if(new==NULL)
    {
        return NULL;
    }
    new->mainlink=NULL;
    new->sublink=NULL;
    new->filecount=1;
    strcpy(new->word,str);
    return new;

}
Status addToHashT(int index,char *str,char *filename,HASH_T *H_table)
{
    
    
    
    MAIN_NODE *temp=H_table[index].link;
    MAIN_NODE *prev=NULL;

    if(temp==NULL)
    {
        MAIN_NODE *mNode = createMainNode(str);
        if(mNode==NULL)
        {
            printf("[INFO]: Creating main node failed\n");
            return FAILURE;
        }
        
        H_table[index].link=mNode;
        addToSubNode(mNode,filename);
        return SUCCESS;
    }
    
    
    // if hash table link is not null
    while(temp!=NULL)
    {
        if(strcmp(temp->word,str)==0)
        {
            addToSubNode(temp,filename);
            return SUCCESS;
        }
        prev=temp;
        temp=temp->mainlink;
    }
    
    MAIN_NODE *mNode = createMainNode(str);
    if(mNode==NULL)
    {
        printf("[INFO]: Creating main node failed\n");
        return FAILURE;
    }
    prev->mainlink=mNode;
    addToSubNode(mNode,filename);
    return SUCCESS;
    
    
    
}
Status traverseFile(char *filename,FILE *fptr,HASH_T *h_table)
{
    char str[20];
    while(fscanf(fptr,"%s",str)!=EOF)
    {
        int index=findIndex(str);
        addToHashT(index,str,filename,h_table);


    }

}
Status createHashTable(HASH_T *H_table,LIST **head)
{
    if(head==NULL)
    {
        printf("[INFO]: No Files to add\n");
        return FAILURE;
    }
    LIST *temp=*head;
    while(temp!=NULL)
    {
        if(traverseFile(temp->filename,temp->fptr,H_table)==FAILURE)
        {
            return FAILURE;
        }
        temp=temp->link;
    }
}
Status createDatabase(HASH_T *H_table,LIST **head)
{
    initialiseHTable(H_table);
    
    if(createHashTable(H_table,head)==SUCCESS)
    {
        printf("[INFO]: Hash table created\n");
        //print hash table
    }
    
    

    
}

void displayDatabase(HASH_T *H_table) 
{
    printf("\n[INFO]: Displaying Hash Table\n");
    
    for (int i = 0; i < 28; i++) {
        if (H_table[i].link != NULL) {
            printf("\nIndex %d:\n", i);

            MAIN_NODE *mainNode = H_table[i].link;
            while (mainNode != NULL) {
                printf("  Word: %s, File Count: %d\n", mainNode->word, mainNode->filecount);

                SUB_NODE *subNode = mainNode->sublink;
                while (subNode != NULL) {
                    printf("    File: %s, Word Count: %d\n", subNode->filename, subNode->wordcount);
                    subNode = subNode->link;
                }

                mainNode = mainNode->mainlink;
            }
        }
    }
}
