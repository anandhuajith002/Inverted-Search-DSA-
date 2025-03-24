#include"types.h"

Status saveDatabase(HASH_T *h_table);

Status updateDatabase(HASH_T *h_table,LIST **head);

Status readFromDatabase(HASH_T *h_table,LIST **head,char *filename);