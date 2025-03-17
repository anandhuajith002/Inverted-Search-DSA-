#include"types.h"


//read and validate main function
Status readAndValidate(int argc,char **argv,LIST **head);

//function to check extension of .txt
Status checkExt(char *filename);

//function to check the file avilabilty
Status fileAvailability(char *filename,FILE **fptr);

//funtion for file content
Status checkFileContent(FILE *fptr);


