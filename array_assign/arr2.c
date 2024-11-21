#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int sum[n];
int a[n][n];

for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		scanf("%d",&a[i][j]);

sum[0]=a[0][1]+a[1][0]+a[1][1];
sum[n-1]=a[n-2][n-1]+a[n-1][n-2]+a[n-2][n-2];

for(int i=1;i<n-1;i++)
  sum[i]=a[i-1][i-1]+a[i+1][i+1]+a[i-1][i]+a[i+1][i]+a[i][i-1]+a[i][i+1]+a[i+1][i-1]+a[i-1][i+1];
		



for (int i=0;i<n;i++)
{
printf("%d:%d\n",a[i][i],sum[i]);

}
return 0;
}
