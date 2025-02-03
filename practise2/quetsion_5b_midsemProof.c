#include <stdio.h>
#include <stdlib.h>

struct a{
    int array[4];
};

void func(struct a arr)
{
    for(int i=0;i<4;i++)
    {
        arr.array[i]=arr.array[i]+1;
    }

    for(int i=0;i<4;i++)
    {
        printf("%d",arr.array[i]);
    }



    printf("\n");

}

int main()
{
    struct a A;
    //A.array[4]= {1,2,3,4};

    for(int i=0;i<4;i++)
    {
        A.array[i]=1;
    }

    

     func(A);

     for(int i=0;i<4;i++)
    {
        printf("%d",A.array[i]);
    }

    return 0;
}