#include"types.h"
#include<string.h>
#include<ctype.h>



int findInd(char *word)
{
    char c=word[0];
    c=tolower(c);
    return c%97;
}

void displayDatabase(HASH_T *H_table)  
{
    printf("+-----------------------------------------------------------+\n");
    printf("| %-7s  %-15s %-7s  %-15s %-5s |\n", 
           "Index", "Word", "f_count", "File Name", "w_count");
    printf("+-----------------------------------------------------------+\n");

    for (int i = 0; i < 28; i++) {
        if (H_table[i].link != NULL) {
            MAIN_NODE *mainNode = H_table[i].link;
            while (mainNode != NULL) {
                printf("|  %-7d  %-15s  %-7d", i, mainNode->word, mainNode->filecount);
                
                SUB_NODE *subNode = mainNode->sublink;
                while (subNode != NULL) {
                    printf("  %-15s %-5d |\n", subNode->filename, subNode->wordcount);
                    subNode = subNode->link;
                    if (subNode) {
                        printf("|           (continued)             ");
                    }
                }

                mainNode = mainNode->mainlink;
            }
        }
    }
    printf("+-----------------------------------------------------------+\n");
}



Status searchDatabase(HASH_T *h_table,char *word)
{
    int index = findInd(word); 
    MAIN_NODE *mainNode = h_table[index].link;

    while (mainNode) {
        if (strcmp(mainNode->word, word) == 0) {
            printf("+------------------+-----------------+\n");
            printf("| Word: %-10s | File Count: %-3d |\n", mainNode->word, mainNode->filecount);
            printf("+------------------+-----------------+\n");
            printf("| %-16s | %-15s |\n", "File Name", "Word Count");
            printf("+------------------+-----------------+\n");

            SUB_NODE *subNode = mainNode->sublink;
            while (subNode) {
                printf("| %-16s | %-15d |\n", subNode->filename, subNode->wordcount);
                subNode = subNode->link;
            }
            printf("+------------------+-----------------+\n");
            printf("[INFO]: Search Successfull\n");
            return SUCCESS;
        }
        mainNode = mainNode->mainlink;
    }

    printf("Word '%s' not found in the database.\n", word);
    return FAILURE;
}


