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

int y[n];


y[0]=a[1][0]+a[0][1];
y[n-1]=a[n-1][n-2]+a[n-2][n-1];

int flag=1;

for(int i=1;i<n-1;i++)
{
y[i]=(a[i][i-1]+a[i][i+1]+a[i-1][i]+a[i+1][i]);
}

for(int i=0;i<n;i++)
{
if(y[i]!=a[i][i])
{
flag=0;
printf("no");
}
}

if(flag==1)
printf("yes");

return 0;
}
