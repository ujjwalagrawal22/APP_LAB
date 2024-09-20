#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

struct Node* createNode(int n)
{
    struct Node *node=(struct Node*) malloc(sizeof(struct Node));
    node->value=n;
    node->next=NULL;
    return node;
}

void insertatEnd(struct Node* head,int n)
{
    struct Node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=createNode(n);
    return;

}

void deleteBegin(struct Node** head)
{
    struct Node* temp=*head;

    *head=(*head)->next;

    free(temp);

    //return head; 

}

void deleteEnd(struct Node* head)
{
    struct Node* temp=head; 

    while(temp->next!=NULL)
    {

    }

}

// deletePos(struct Node* head)
// {

// }

void printlist(struct Node* head)
{
    struct Node* temp=head;

    while(temp!=NULL)
    {
        printf("%d->",temp->value);
        temp=temp->next;
    }
        printf("NULL \n");
        return;
}

int main()
{
    struct Node *head=createNode(1);
    
    insertatEnd(head,2);
    insertatEnd(head,5);
    insertatEnd(head,7);
    insertatEnd(head,4);
    printlist(head); 

    deleteBegin(&head);
    printlist(head);

    deleteEnd(head);
    printlist(head);

    // deletePos(head);
     //printlist(head);    



    return 0;
}

