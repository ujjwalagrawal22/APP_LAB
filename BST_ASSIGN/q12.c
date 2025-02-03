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
struct Node *SearchNode(struct Node*,int);
// struct Node *inordersuccess(struct Node *);
// struct Node *inorderpred(struct Node *);
struct Node* inPredeccessor(struct Node *,int);
struct Node* predHelper(struct Node*);
struct Node* inSuccessor(struct Node *,int);
struct Node* sucHelper(struct Node*);


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
    // if(search->data)
    // printf("found\n");
    // else
    // printf("not found\n");

    // struct Node* search=SearchNode(root,75);
    // struct Node *inordersuc=inordersuccess(search);
    // printf("%d\n",inordersuc->data);
 

    // if(search->data)
    // printf("found\n");
    // else
    // printf("not found\n");

    // search=SearchNode(root,75);
    // struct Node *inorderpre=inorderpred(root,search);
    // printf("%d",inorderpre->data);


    //printf("%d",search->data);
    struct Node* inorderpre=inPredeccessor(root,9);
    printf("%d \n",inorderpre->data);

    struct Node* inordersuc=inSuccessor(root,9);
    printf("%d",inordersuc->data);
   

    

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




struct Node *SearchNode(struct Node *root,int k)
{
    if(root==NULL || root->data == k)  return root;

    if(k<root->data)
    return SearchNode(root->left,k);

    return SearchNode(root->right,k);


}


struct Node* predHelper(struct Node* root){

    while(root->right!=NULL)
    {
        root=root->right;
    }

    return root;

}

struct Node* inPredeccessor(struct Node *root,int target){
    struct Node* search=SearchNode(root,target);
    if(search==NULL) return NULL;

    //case 1(if left subtree available)
    if(search->left!=NULL)
    return predHelper(search->left);

    //case 2(if left subtree not available)
    struct Node*pred=NULL;
    struct Node*curr=root;

    while(curr!=NULL)
    {
        if(target<curr->data)
        {
            curr=curr->left;
        }

        else if(target>curr->data)
        {
            
            pred=curr;
            curr=curr->right;
        }

        else 
        break;

    }

    return pred;

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

struct Node* sucHelper(struct Node* root)
{
    while (root->left!=NULL)
    {
        root=root->left;   
    }
    return root;
    
}

struct Node* inSuccessor(struct Node *root,int target)
{
    struct Node* search=SearchNode(root,target);

    if(search==NULL) return NULL;

    if(search->right!=NULL)
    return sucHelper(search->right);

    struct Node *successor=NULL;
    struct Node *curr=root;

    while(curr!=NULL)
    {
        if(target<curr->data)
        {
            successor=curr;
            curr=curr->left;
        }

        else if(target>curr->data)
        {
            curr=curr->right;
        }
        else
        break;
    }

    return successor;

}
// struct Node *inordersuccess(struct Node *root)
// {
//     if(root==NULL) return NULL;

//     struct Node *temp=root->right;

//     while(temp!=NULL && temp->left!=NULL)
//     {
//         temp=temp->left;
//     }

//     return temp;

// }
// struct Node *inorderpred(struct Node *root)
// {
//     if(root==NULL) return NULL;

//     struct Node *temp=root->left;

//     while(temp!=NULL && temp->right!=NULL)
//     {
//         temp=temp->right;
//     }

//     return temp;
// }