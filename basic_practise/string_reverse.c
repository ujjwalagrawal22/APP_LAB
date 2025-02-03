#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int c;
    int i;
    int j;
    // int n;

    char s[1000];

    scanf("%s",s); //enter the string stops as and when ne wline is encountered

    for (i=0,j=strlen(s)-1;i<j;i++,j--) //important to note that spaces and tabs will be 
    {                                   //considered end of string
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }

    printf("%s",s); //print the final reversed sttring till first space is encountered

      
    return 0;
}