#include <stdio.h>
#include <stdlib.h>

struct dset
{
int n;
int *parent;
int *rank;
};

struct dset *createset(int n)
{
    struct dset *set=(struct dset*)malloc(sizeof(struct dset));
    set->n=n;
    set->parent=(int *)malloc(n * sizeof(int));
    set->rank=(int *)malloc(n * sizeof(int));

    for(int i=0;i<n;i++)
    {
        set->parent[i]=i;
        set->rank[i]=0;

    } 

    return set;
}

int findSet(int x,struct dset *set)
{
    if(set->parent[x]!=x)
    {
        set->parent[x]=findSet(set->parent[x],set); //path compression 
    }

    return set->parent[x];

}

void findUnion(int x,int y,struct dset *set)
{
  int a=findSet(x,set);
  int b=findSet(y,set);

  if(a!=b)
  {
    if(set->rank[a]>set->rank[b])
    {
        set->parent[b]=a;
    }
    else if(set->rank[a]<set->rank[b])
    {
        set->parent[a]=b;    
    }
    else if(set->rank[a]==set->rank[b])
    {
        set->parent[a]=b;
        set->rank[a]++;
    }
  }  

}

int main()
{
    int a;
    scanf("%d",&a);
    struct dset *set=createset(a);  //set created of size n and returned(make-set)

    findUnion(0,1,set);
    findUnion(2,3,set);
    findUnion(3,5,set);
    findUnion(5,7,set);

    printf("Find representative of elements:\n");
    for (int i = 0; i < a; i++) {
        printf("Element %d -> Root: %d\n", i, findSet(i, set));
    }

    

    return 0;
}