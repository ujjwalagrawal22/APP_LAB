#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000 //using macros

// void swap(char *a,char *b)
// {
//     char t;
//     t=*a;
//     *a=*b;
//     *b=t;
// }

int main()
{
    int n;
    scanf("%d",&n); //to input number of strings 

    char a[n][MAX];

    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }

    char temp[MAX];
    int val;

    // to compare and print in lexicographically sorted manner

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        val=strcmp(a[i],a[j]);
        if(val<0)
        {
            strcpy(temp,a[i]);
            strcpy(a[i],a[j]);
            strcpy(a[j],temp);

        }
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%s ",a[i]);
    }

    printf("\n");

    //to print unique names

       for(int i=0;i<n;)
    {
        
        val=strcmp(a[i],a[i+1]);
        if(val==0)
        {
            printf("%s ",a[i]);
            i=i+2;

        }
        else
        {
        printf("%s ",a[i]);
        i++;
        }
        
    }


    return 0;
}