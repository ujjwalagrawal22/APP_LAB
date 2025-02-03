#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c;

    a=0;
    b=1;

    int fibo[17];

    int x,y;

    scanf("%d%d",&x,&y);

    fibo[0]=0;
    fibo[1]=1;

    // printf("%d %d ",a,b);

    for(int i=2;i<17;i++)
    {
        c=a+b;
        fibo[i]=c;
        a=b;
        b=c;
    }  
    int flag=0;

    for(int i=0;i<17;i++)
    {
         for(int j=0;j<i;j++)
        {
            if(x>y)
            {
            if((fibo[i]-fibo[j])==(x-y))
            {
                printf("%d - %d=%d - %d",x,y,fibo[i],fibo[j]);
                flag=1;
                return 0;
            }
            }

            if(x<y)
            {
            if((fibo[i]-fibo[j])==(y-x))
            {
                printf("%d - %d=%d - %d",x,y,fibo[i],fibo[j]);
                flag=1;
                return 0;
            }
            }
        }  
    }  

     if(flag==0)
        {
            printf("impossible");
        }


    return 0;
}