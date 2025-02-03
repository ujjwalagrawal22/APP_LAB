#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *fptr;

    //writing 
    fptr = fopen("data.txt","w");
    fprintf(fptr,"Trial!!"); 
    fclose(fptr);

    //appending 
    fptr=fopen("data.txt","a");
    fprintf(fptr,"\nHi everybody!");
    fclose(fptr);

    //file reading 
    fptr=fopen("data.txt","r");
    char string[1000];
    fgets(string,1000,fptr); //storing data of file in char string
    printf("%s",string); //printing the data from file 
    fclose(fptr);

    return 0;
}