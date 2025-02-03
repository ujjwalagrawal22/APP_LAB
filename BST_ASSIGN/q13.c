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
void findAncestors(struct Node*,int);

int main()
{
    struct Node *root=NULL;

    int n; //no of nodes in bst
    int f; //no of value to be searched

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);

        root=insert(root,a);
    }

    findAncestors(root,20);



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
void findAncestors(struct Node *root,int target)
{
    struct Node* search=searchTree(root,target);
    if(search==NULL) return ;

    struct Node*pred=NULL;
    struct Node*curr=root;

    while(curr!=NULL && curr!=search)
    {
        if(target<curr->data)
        {
            pred=curr;
            printf("%d ",pred->data);
            curr=curr->left;
        }

        else if(target>curr->data)
        {
            
            pred=curr;
            printf("%d ",pred->data);
            curr=curr->right;
        }

       
    }

    return;
}