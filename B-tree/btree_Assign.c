/*  1. Write a program to with positive integers as data to from a B-tree. Input is given in the following
sequence: t, x1, x2, … xn . If xi is positive, it must be inserted. If it is negative, the value, if exists, should
be removed. Input is read until it is zero. Then print all the values in the tree in level order traversal.
Input:
2
2 1 3 7 4
-2
11
-7
8
-3
7 3 2 6
0

 */


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    //int d;  //minimum degree
    int c;  //current number of keys in node
    int *keys;  // array of keys  
    struct Node **child;  // array of child pointers 
    int leaf;             //true/false 0/1 whether node leaf or not 

};

void B_treeInsert(struct Node**,int,int);
struct Node *B_treeDelete(struct Node*,int);
void B_treeDisplay(struct Node*);
struct Node *B_treeCreateNode(int);
int main()
{
    int t;

    scanf("%d",t);

    struct Node *root=B_treeCreateNode(1);


    int in;

    while(in!=0)
    {
        scanf("%d",in);

        if(in>0)
        B_treeInsert(&root,in);

        else if(in<0)
        B_treeDelete(&root,in);

        else
        break;
    }

    B_treeDisplay(root);


    return 0;
}

struct Node *B_treeCreateNode(int leaf)
{
    struct Node *Node=(struct Node*)malloc(sizeof(struct Node));
    Node->c=0;
    Node->child=(struct Node **)malloc((2 * t) * sizeof(struct Node*));
    Node->keys=(int *)malloc((2*t-1) * sizeof(int));
    Node->leaf=leaf;
    return Node;
}

void B_treeInsert(stuct Node **root,int val,int t)
{
    struct Node *r=*root;

    if(r->c==(2*t-1))
    {
        struct Node *s=B_treeCreateNode(0);
        *root=s;
        s->child[0]=r;
        splitChild();
        B_treeInsertNonFull();

    }
    else
    {
        B_treeInsertNonFull();

    }
}

void B_treeInsertNonFull()
{

}

void splitChild()
{
    
}

