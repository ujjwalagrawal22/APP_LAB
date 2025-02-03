#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int n)
{
    struct Node *node=(struct Node *)malloc (sizeof (struct Node));
    node->value=n;
    node->next=NULL;
    node->prev=NULL;
    return node;
    

}
void insertatEnd(struct Node **head,int n)
{
    

    //struct Node *newnode=createNode(n);

    if(*head==NULL)
    {
        *head=createNode(n);
    }

    else
    {
    struct Node *temp=*head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=createNode(n);
    temp->next->prev=temp;
    }

    return;
}

void printlist(struct Node *head)
{
    struct Node *temp=head;

    while(temp!=NULL)
    {
        printf("%d->",temp->value);
        temp=temp->next;
    }

        printf("NULL \n");

    return;
}

void printlistback(struct Node *head)
{
    struct Node *temp=head;

    while(temp->next!=NULL)
    {
        //printf("%d->",temp->value);
        temp=temp->next;
    }

    while(temp!=NULL)
    {
        printf("%d->",temp->value);
        temp=temp->prev;

    }

        printf("NULL \n");

        return;

    
}

// void small_LL(struct Node *head)
// {
//     struct Node *temp=head;
//     int min;
//     min=temp->value;

//     do{
        
        
//         if(temp->value<min)
//         min=temp->value;

//         temp=temp->next;

        
        
//     }while(temp->next!=head);

//     printf("%d",min);
// }

int main()
{
    int N,x;
    scanf("%d",&N);

    struct Node *head=NULL;

    while(N>0)
    {
        scanf("%d",&x);
        insertatEnd(&head,x);  
        N--;

    }

    printlist(head);
    printlistback(head);
    // small_LL(head);

    return 0;
}