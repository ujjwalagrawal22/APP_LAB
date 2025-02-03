#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int a)
{
    struct Node *node=(struct Node*)malloc (sizeof(struct Node));

    node->data=a;
    node->next=NULL;

    return node;
}

 struct Node *insertNode(struct Node *head,int a)
{
    if(head==NULL) return createNode(a);

    struct Node *temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=createNode(a);

    return head;

}

struct Node *reverseLL(struct Node *head)
{
    struct Node *curr=head;
    struct Node *prev=NULL;
    struct Node *next=NULL;

    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;

    return head;
}

void printList(struct Node *head)
{
    struct Node *temp=head;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return ;
}

int main()
{
    int n;
    struct Node *head=NULL;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);

        head=insertNode(head,a);
    }

    printList(head);

    head=reverseLL(head);

    printf("\n");

    printList(head);

    return 0;
}