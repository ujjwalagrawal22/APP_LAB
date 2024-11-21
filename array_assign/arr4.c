#include <stdio.h>
int main()
{
        int n;
        scanf("%d",&n);
        int a[n][n];
        for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                        scanf("%d",&a[i][j]);

        printf("Along rows:\n");
        int t[n][n];

      /*  for(int i=0;i<n;i++)
        {       for(int j=0;j<n;j++)
                {
                t[i][j]=a[i][j];
                }
                
                for(int j=0;j<n;j++)
                {
                  if( t[i][j]!=a[i][j])
                   {
                    printf("%d",a[i][j]);
                   }
  
return 0;
}



