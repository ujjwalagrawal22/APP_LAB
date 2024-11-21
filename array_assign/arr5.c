#include<stdio.h>
#include<string.h>
int main()
{
int n;
scanf("%d",&n);    //to enter number of strings

char a[n][50];      // [n]- no of elements, [50]-max length of string

for(int i=0;i<n;i++)
{
scanf("%s",a[i]);
}

int temp;
char t[50];

for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++)
{
temp=strcmp(a[i],a[j]);
if(temp>0)
{
strcpy(t,a[j]);
strcpy(a[j],a[i]);
strcpy(a[i],t);
}
}}

for(int i=0;i<n;i++)
{
printf(" %s ",a[i]);
}

return 0;
}
