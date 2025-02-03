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
int checkTree(struct Node*);

int main()
{
    struct Node *root=NULL;

    int n; //no of nodes in bst
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);

        root=insert(root,a);
    }

    int check=sumTree(root);

    if(check)
    printf("yes");
    else
    printf("no");

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
int checkTree(struct Node* root)
{
    if(root==NULL) return 1;

    return (root->data) == checkTree(root->left)+checkTree(root->right); 
}