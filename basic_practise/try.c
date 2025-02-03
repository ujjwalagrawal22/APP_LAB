#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n=1564;

    printf("%d %d \n",1564/100,1564%1000);
    int temp=n;
    int count=0;
    while(temp!=0)
    {
        temp=temp/10;
        count++;
        
    }

    printf("count:%d\n",count);
    int new=n%(int)(pow(10,count-1));
    printf("%d",new);
    return 0;
}