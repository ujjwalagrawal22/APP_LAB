#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>
struct Node{
    int value;
    struct Node *next;
};

struct Node* createNode(struct Node *head,int n)
{   
   
    struct Node *node=(struct Node*) malloc(sizeof(struct Node));
    node->value=n;
    // struct Node *temp=head; // read about this correction
    node->next=node; // remember this point
    return node;
}

void insertatEnd(struct Node *head,int n)
{
    struct Node *temp=head;

    while(temp->next!=head)
    {
        temp=temp->next;
    }

    temp->next=createNode(head,n);
    temp->next->next=head; //read about this correction



}

void printlist (struct Node* head)
{
    struct Node* temp=head;

    do
    {
        printf("%d-> ",temp->value);
        temp=temp->next;
    }while(temp!=head);  // remember to use "do while" in circular linked list

       //printf("NULL \n");
        return;
}
int main()
{   
    struct Node *head=NULL;
    head=createNode(head,1);
    
    insertatEnd(head,2);
     //printlist(head); 
    insertatEnd(head,5);
     //printlist(head); 
    insertatEnd(head,7);
    insertatEnd(head,4);

    printlist(head); 

   

    return 0;
}