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
int countLeaf(struct Node*);
int sumLeaf(struct Node*);

int main()
{
    struct Node *root=NULL;

    // root=insert(root,5);
    // insert(root,3);
    // insert(root,8);
    // insert(root,1);
    // insert(root,4);
    int n; //no of nodes in bst
    
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);

        root=insert(root,a);
    }

    int count ;
    count=countLeaf(root);
    printf("%d\n",count);

    int sum;
    sum=sumLeaf(root);
    printf("%d\n",sum);


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

int countLeaf(struct Node* root)
{
    if(root->left==NULL && root->right==NULL) return 1 ;

    if(root->left==NULL) return countLeaf(root->right) ;

    if(root->right==NULL) return countLeaf(root->left) ;

    return countLeaf(root->left)+ countLeaf(root->right);

}
int sumLeaf(struct Node* root)
{

    if(root->left==NULL && root->right==NULL) return root->data;

    if(root->left==NULL) return sumLeaf(root->right) ;

    if(root->right==NULL) return sumLeaf(root->left) ;

    return sumLeaf(root->left)+ sumLeaf(root->right);

    // if(root==NULL) return 0;

    // if(root->left==NULL && root->right==NULL) return root->data;

    // return sumLeaf(root->left)+sumLeaf(root->right);

}