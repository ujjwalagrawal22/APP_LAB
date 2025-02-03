//BST Code
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int);
struct Node *insert(struct Node*,int);
void preorder(struct Node*);
void inorder(struct Node*);
void postorder(struct Node*);
void freeTree(struct Node*);
struct Node *searchTree(struct Node*,int);
int DistTwoNode(struct Node*,int,int);

int main()
{
    struct Node *root=NULL;

    int n; //no of nodes in bst
    int first,second; //no of value to be searched

    scanf("%d%d%d",&n,&first,&second);

    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);

        root=insert(root,a);
    }

    int d=DistTwoNode(root,first,second);
    printf("%d",d);

    freeTree(root);

    return 0;
}

struct Node *createNode(int data)
{
    struct Node *node=malloc(sizeof(struct Node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;

}
struct Node *insert(struct Node* root,int data)
{
    if(root==NULL) return createNode(data);

    if(data < root->data)
        root->left=insert(root->left, data);
    else
        root->right=insert(root->right, data);

    return root;
}

void preorder(struct Node* root)
{
    if(root !=NULL)
    {
        printf("%d_",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct Node* root)
{
   if(root !=NULL) 
   {
        inorder(root->left);
        printf("%d_",root->data);
        inorder(root->right);
   }
}
void postorder(struct Node* root)
{
    if(root !=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d_",root->data);
    }
}
void freeTree(struct Node* root)
{
    if(root!=NULL)
    {
        free(root->left);
        free(root->right);
        free(root);
    } 

}

struct Node *searchTree(struct Node* root,int val)
{
    if(root==NULL || root->data==val) return root;

    if(val<root->data)
    return searchTree(root->left,val);

    else
    return searchTree(root->right,val);
}

int DistTwoNode(struct Node *root,int first,int second)
{
   
    if(root==NULL) return 0;

    if(first<root->data && second<root->data)
    return DistTwoNode(root->left,first,second);

    if(first>root->data && second>root->data)
    return DistTwoNode(root->right,first,second);
    
    return disthelper(`);//DistTwoNode(root->left,first,second)+DistTwoNode(root->right,first,second);
}