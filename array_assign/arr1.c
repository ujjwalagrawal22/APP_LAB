#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n][n];
	int sum=0;


	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i][i]);
		sum=sum+a[i][i];
	}

	int j=1;

	while(sum>(j*((n*n)-n)))
	{
		j++;
	}
	printf("%d",j);
return 0;
}

