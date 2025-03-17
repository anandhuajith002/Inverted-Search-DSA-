#include"types.h"
#include"operations.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Status printList(LIST *head)
{
    if(head==NULL)
    {
        return EMPTY;
    }
    LIST *temp=head;
    while(temp)
    {
        printf("%s ",temp->filename);
        temp=temp->link;
    }
    return SUCCESS;

}

Status addToList(LIST **head,char *filename,FILE *fptr)
{
    LIST *new=malloc(sizeof(LIST));
    if(new==NULL)
    {
        return FAILURE;
    }
    new->fptr=fptr;
    new->link=NULL;
    strcpy(new->filename,filename);

    if(*head==NULL)
    {
        *head=new;
        return SUCCESS;
    }
    LIST *temp=*head;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=new;
    return SUCCESS;

}
Status noDuplicate(LIST *head,char *filename)
{
    if(head==NULL)
    {
        return SUCCESS;
    }
    LIST *temp=head;
    while (temp!=NULL)
    {
        if(strcmp(filename,temp->filename)==0)
        {
            return DUPLICATE;
        }
        temp=temp->link;
    }
    return SUCCESS;
    

    
}
