#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[1000];
    int hash[26]={0};

    scanf("%s",word);

    int l=strlen(word);

    //  for(int i=0;i<l;i++)
    // {

     
    //     printf("%d ",word[i]);
    // }





    // printf("%d",l);

    for(int i=0;i<l;i++)
    {
        if(word[i]!=word[i+1])
        hash[word[i]- 'a']++;
    }

     for(int i=0;i<26;i++)
    {

        if(hash[i]>0)
        printf("%4c%6d\n",i+97,hash[i]);
    }




    // fgets(word,10,stdin);
    // printf("%s",word);


    return 0;
}