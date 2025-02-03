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
void findDepth(struct Node*,int);
int findHeight(struct Node*);

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

    findDepth(root,0);
    printf("\n");
    findHeight(root);

    // printf("Inorder:");
    // inorder(root);
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
void findDepth(struct Node* root,int depth)
{


    if(root==NULL) return;

    printf("%d : %d ",root->data,depth);
    findDepth(root->left,depth+1);
    findDepth(root->right,depth+1);
    //depth=0;

}

int findHeight(struct Node* root)
{


    if(root==NULL) return -1;

    int left=findHeight(root->left);
    int right=findHeight(root->right);
    int nodeh=1+(left>right?left:right);
    printf("%d : %d ",root->data,nodeh);
    return nodeh;

}
