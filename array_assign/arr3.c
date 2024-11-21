#include<stdio.h>
void transpose(int *a,int *b,int arr[][*b])
{
int t[*b][*a];
          for(int i=0;i<*a;i++)
        {
                for(int j=0;j<*b;j++)
                {
                 t[j][i]=arr[i][j];

                }

        }

           for(int i=0;i<*b;i++)
        {
               for(int j=0;j<*a;j++)
                {
                 printf(" %d ",t[i][j]);

                }
                printf("\n");
        }
}

int main()
{
        int m,n;
        scanf("%d %d",&m,&n);
        int a[m][n];

        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        scanf("%d",&a[i][j]);
                }
                printf("\n");
        }

        transpose(&m,&n,a);
        return 0;
}

