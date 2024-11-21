#include<stdio.h>
#include<string.h>

int main()
{
int n;
scanf("%d",&n);

char a[n][50];

for(int i=0;i<n;i++)
{
scanf("%s",a[i]);
}

int flag=1;
int len;
char temp[100];

for(int i=0;i<n;i++)
{
len=strlen(a[i]);
strcpy(temp,a[i]);

for(int j=0;j<len/2;j++)
{
if(temp[j]!=temp[len-1-j])
{
flag=0;
}
}
if(flag==0)
{
printf("No \n");
flag=1;
}
else
{
printf("yes \n");
}
//flag=1;
}
	
return 0;
}
