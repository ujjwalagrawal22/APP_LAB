#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
int compareTree(struct Node*,struct Node*);

int main()
{
    struct Node *froot=NULL;
    struct Node *sroot=NULL;
    int n;
    int f;
    

    scanf("%d",&n);
    scanf("%d",&f);
    int found[f];

    for(int j=0;j<f;j++)
   {
    froot=NULL;
    sroot=NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        froot=insert(froot,a);
    }

    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        sroot=insert(sroot,a);
    }

    found[j]=compareTree(froot,sroot);
    
    
    
    }

    for(int i=0;i<f;i++)
    {
    if(found[i])
    printf("y\n");
    else
    printf("n\n");
    }
    

    // root=insert(root,5);
    // insert(root,3);
    // insert(root,8);
    // insert(root,1);
    // insert(root,4);

    // printf("Preorder:");
    // preorder(root);
    // printf("\n");

    // printf("Inorder:");
    // inorder(root);
    // printf("\n");

    // printf("Postorder:");
    // postorder(root);
    // printf("\n");

    freeTree(froot);
    freeTree(sroot);

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
        printf(" %d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct Node* root)
{
   if(root !=NULL) 
   {
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
   }
}
void postorder(struct Node* root)
{
    if(root !=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ",root->data);
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

int compareTree(struct Node* froot,struct Node* sroot)
{
    if(froot==NULL && sroot==NULL) return 1;
    if(froot==NULL || sroot==NULL) return 0;

    return((froot->data==sroot->data) && compareTree(froot->left,sroot->left) && compareTree(froot->right,sroot->right));
    

}