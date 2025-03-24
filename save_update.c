#include"types.h"
#include<stdio.h>
#include"save_update.h"
#include"validate.h"
#include"create.h"
#include"operations.h"

Status saveDatabase(HASH_T *h_table)
{
    printf("[INFO]: Enter the filename to save : ");
    char file[30];
    scanf("%s",file);
    if(checkExt(file)==FAILURE)
    {
        printf("Enter valid Extension\n");
        return FAILURE;
    }
    
    FILE *fptr=fopen(file,"w");
    if(fptr==NULL)
    {
        return FAILURE;
    }
    for(int i=0;i<28;i++)
    {
        if(h_table[i].link!=NULL)
        {
            MAIN_NODE *mainNode=h_table[i].link;
            while(mainNode!=NULL)
            {
                fprintf(fptr,"#%d;%s;%d;",i,mainNode->word,mainNode->filecount);
                
                SUB_NODE *sub=mainNode->sublink;
                while(sub!=NULL)
                {
                    fprintf(fptr,"%s;%d;",sub->filename,sub->wordcount);
                    sub=sub->link;
                }

                fprintf(fptr,"#\n");
                mainNode=mainNode->mainlink;
            }
        }
    }
    printf("[INFO]:Saved database to save.txt\n");
    fclose(fptr);
    return SUCCESS;
}
Status readFromDatabase(HASH_T *h_table,LIST **head,char *filename)
{
    FILE *fptr=fopen(filename,"r");
    if(fptr==NULL)
    {
        printf("[INFO]: Opening file failed\n");
        return FAILURE;
    }
    int index,filecount,wordcount;
    char word[50],file[50];
    while(fscanf(fptr,"#%d;%[^;];%d;",&index,word,&filecount)!=EOF)
    {
        // printf("\n%d,%s,%d----",index,word,filecount);
        MAIN_NODE*temp=h_table[index].link;
        
        if(temp==NULL)
        {
            temp=createMainNode(word);
            h_table[index].link=temp;
            temp->filecount=filecount;
        }
        else
        {
            while(temp->mainlink)
            temp=temp->mainlink;
            temp->mainlink=createMainNode(word);
            temp->mainlink->filecount=filecount;
            temp=temp->mainlink;
        }
        
        SUB_NODE *sub=temp->sublink;
        for(int i=0;i<filecount;i++)
        {
            fscanf(fptr,"%[^;];%d;",file,&wordcount);
            SUB_NODE *new=createSubNode(file); 
            new->wordcount=wordcount;

            if(noDuplicate(*head,file)!=SUCCESS)
            {
                removeFromList(head,file);
            }
            
            if(sub==NULL)
            {
                temp->sublink=new;
                sub=new;
            }
            else
            {
                while(sub->link!=NULL)
                sub=sub->link;
                
                sub->link=new;
                sub=new;
            }
            // printf("=%s,%d=",file,wordcount);
        }
        fscanf(fptr,"#\n");
    }
    fclose(fptr);
}

Status updateDatabase(HASH_T *h_table,LIST **head)
{
    
    printf("Enter the database filename : ");
    char filename[50];
    scanf("%s",filename);
    if(checkExt(filename)==FAILURE)
    {
        printf("Enter valid Extension\n");
        return FAILURE;
        
    }
    initialiseHTable(h_table);
    if(readFromDatabase(h_table,head,filename)==FAILURE)
    {
        printf("[INFO]: Reading from database failed\n");
        return FAILURE;
    }
    
    if(createHashTable(h_table,head)==SUCCESS)
    {
        printf("[INFO]: Database Updated\n");
        //print hash table
    }


}