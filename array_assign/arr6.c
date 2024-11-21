#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int a[n][n];

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}

int sumr[n];
int sumc[n];

for(int i=0;i<n;i++)
{
sumr[i]=0;
sumc[i]=0;
}

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
sumr[i]+=a[i][j];
}
}

int b[n][n];

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
b[j][i]=a[i][j];
}
}

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
sumc[i]+=b[i][j];
}
}

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(sumr[i]==sumc[j])
{
printf("Row:  %d \n",i);
printf("Column: %d \n",j);
}
}

}

return 0;
}
