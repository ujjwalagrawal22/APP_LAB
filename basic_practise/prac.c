#include<stdio.h>

int main()
{
	int n;

	scanf("%d",&n);

	int in[n];

	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
	}

	printf("in: ");
    printf("%d ",in[0]);

	for(int i=0;i<n;i++)
        {
            if(((2*i)+1)<n && in[(2*i)+1]<in[i])
             printf("%d ",in[(2*i)+1]);
		    if(((2*i)+2)<n && in[(2*i)+2]<in[i])
             printf("%d ",in[(2*i)+2]);

                // printf("%d ",in[i]);
        }
        
	printf("\n");

	printf("ex: ");


	for(int i=0;i<n;i++)
	{
		if(((2*i)+1)<n && in[(2*i)+1]>=in[i])
			printf("%d ",in[(2*i)+1]);
		if(((2*i)+2)<n && in[(2*i)+2]>=in[i])
			printf("%d ",in[(2*i)+2]);
	}

	printf("\n");



	return 0;

}
