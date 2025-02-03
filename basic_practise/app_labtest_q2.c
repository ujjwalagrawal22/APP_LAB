#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int  checkprime(int n)
{
    int flag=1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }


    return -1;
}

int lastDigit(int n)
{
    int new;
    new=n/10;
    return new;
}

int firstDigit(int n)
{
    int temp=n;
    int count=-1;
    while(temp!=0)
    {
        temp=temp/10;
        count++;
    }

    int new=n% (int)(pow(10,count));

    return new;

}

int main()
{
    int n;
    scanf("%d",&n);

    if(n>=2 && n<10)
    {
        int c=checkprime(n);
        if(c==0)
        {
            printf("no");
        }
        else
        printf("yes");
        
    }

    else
    {
        int c=checkprime(n);

        if(c==0)
        {
            int last=lastDigit(n);
            int first=firstDigit(n);
            int ld,fd;
            ld=checkprime(last);
            fd=checkprime(first);

            if(fd==-1 && ld==-1)
            printf("yes");

            else
            printf("no");

            
        }
        else
        {
            printf("yes");
        }

    }



    return 0;
}