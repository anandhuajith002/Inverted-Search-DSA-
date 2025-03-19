#include"types.h"
#include"validate.h"
#include"operations.h"
#include<string.h>
#include<stdlib.h>

Status readAndValidate(int argc,char **argv,LIST **head)
{
    *head=NULL;
    
    if(argc<2)
    {
        printf("[INFO]: Error in number of arguments\n");
        exit(0);
    }

    for(int i=1;i<argc;i++)
    {
        FILE *fptr;
        if(checkExt(argv[i])==SUCCESS)
        {
            if(fileAvailability(argv[i],&fptr)==SUCCESS)
            {
                if(checkFileContent(fptr)==SUCCESS)
                {
                    if(noDuplicate(*head,argv[i])==SUCCESS)
                    {
                        if(addToList(head,argv[i],fptr)==SUCCESS)
                        {
                            printf("[INFO]: %s added to list\n");
                        }
                        else
                        {
                            printf("[INFO]: %s failed to list list\n",argv[i]);
                        }
                    }
                    else
                    {
                        printf("[INFO]: %s is a duplicate file\n",argv[i]);

                    }
                }
                else
                {
                    printf("[INFO]: %s has no content avilable\n",argv[i]);
                }
                
            }
            else
            {
                printf("[INFO]: %s file not avilable\n",argv[i]);

            }
        }
        else
        {
            printf("[INFO]: %s has wrong extention\n",argv[i]);
        }
    }
    return SUCCESS;

}

Status checkExt(char *filename)
{
    char *sub=strstr(filename,".txt");
    if(sub==NULL || strcmp(sub,".txt")!=0)
    {
        return FAILURE;
    }
    return SUCCESS;
}

Status fileAvailability(char *filename,FILE **fptr)
{
    *fptr=fopen(filename,"r");
    if(fptr==NULL)
    {
        return FAILURE;
    }
    return SUCCESS;

}

Status checkFileContent(FILE *fptr)
{
    fseek(fptr,0,SEEK_END);
    if(ftell(fptr)!=0)
    {
        fseek(fptr,0,SEEK_SET);
        return SUCCESS;
    }
    return FAILURE;

}

