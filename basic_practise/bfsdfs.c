#include <stdio.h>
#include <stdlib.h>

int visitedd[1000]={0};
int n;
int visitedb[1000]={0};

int queue[1000];

int rear=0;
int front=0;

int isEmpty()
{
    if(rear==front)
    return 1;

    return 0;
}

void push(int x)
{
    queue[rear++]=x;
}

void pop()
{
    front++;
}

void bfs(int a[n][n],int start)
{
    visitedb[start]=1;
    push(start);

    while (!isEmpty())
    {
        int temp=queue[front];
        printf("%d",temp);
        pop();
        for (int i = 0; i < n; i++)
        {
            if(visitedb[i]!=1 && a[temp][i]==1)
            {
                push(i);
                visitedb[i]=1;
            }
        }
        
    }
    
}

void dfs(int a[n][n],int start)
{
    visitedd[start]=1;
    printf("%d ",start);

    for(int i=0;i<n;i++)
    {
        if(visitedd[i]!=1 && a[start][i]==1)
        {
            dfs(a,i);
        }
    }
}


int main()
{
    scanf("%d",&n);

    int a[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }

    printf("\n");

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    dfs(a,0);

    printf("\n");

    bfs(a,0);

    return 0;
}

// void dfs(int a[n][n],int start)
// {
//     visitedd[start]=1;
//     printf("%d",start);

//     for(int i=0;i<n;i++)
//     {
//         if(visitedd[i]!=1 && a[start][i]==1)
//         dfs(a,i);
//     }
// }

// void bfs(int a[n][n],int start)
// {
//     visitedb[start]=1;
//     push(start);

//     while(!isEmpty())
//     {
//         int temp=queue[front];
//         printf("%d",temp);
//         pop();

//         for(int i=0;i<n;i++)
//         {
//             if(visitedb[i]!=1 && a[temp][i]==1)
//             {
//                 push(i);
//                 visitedb[i]=1;
//             }
//         }
//     }
// }