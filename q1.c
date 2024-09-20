#include<stdio.h>
#include<stdlib.h>
struct Node{
    int value;
    struct Node *next;
};

struct Node* createNode(int n)
{
struct Node *node=(struct Node *) malloc (sizeof(struct Node));
node->value=n;
node->next=NULL;

return node;
    
}

void insertatend(struct Node *head,int n)
{
    struct Node *temp=head;; 
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=createNode(n);
    return;
}
void printList(struct Node *head)
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->value);
        temp=temp->next;
    }
        printf("NULL");

        return;
}
void insertatBegin(struct Head **head,int n)
{
    struct Node *temp;
    temp=createNode(n);
    temp -> next = *head ;
    *head = temp;

    temp=NULL;

    return;
    
}

void insertatPos(struct Head *head,int n,int k)
{
    struct Node *temp=head;
    
    for(int i=1;i<k;i++)
    {
        temp=temp->next;
    }

    struct Node *t= temp->next;

    temp->next=createNode(n);
    temp->next->next=t;
    return;

}

int main()
{


     int n,k;

     scanf("%d",&n);
     scanf("%d",&k);

    struct Node *head= createNode(1);

    insertatend(head,2);
    insertatend(head,5);
    insertatend(head,7);
    insertatend(head,4);

    insertatBegin(&head,n);
    printList(head);
    printf("\n");
    
    head=head->next;

    insertatend(head,n);
    printList(head);
    printf("\n");

    insertatPos(head,n,k);
    printList(head);

    return 0;
}