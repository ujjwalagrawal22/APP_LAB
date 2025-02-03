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

struct Node *reverse_LL(struct Node *head)
{
    struct Node *prev=NULL;
    struct Node *current=head;
    struct Node *next=NULL;

    while (current!=NULL)
    {   
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }


    head=prev;

    printf("%d\n",prev->value);
    printf("%d\n",current->value);

    if(next==NULL)                                      
    {
        printf("NULL");
    }
    return head;

    

}

int  max_LL(struct Node *head)
{
    struct Node *temp=head;
    int max;
    max=temp->value;

    while(temp!=NULL)
    {
        if(temp->value>max)
        max=temp->value;

        temp=temp->next;
    }

    printf("%d \n",max);

    return max;

}

int min_LL(struct Node *head)
{
        struct Node *temp=head;
        int min; 
        min=temp->value;

    while(temp!=NULL)
    {
        if(temp->value<min)
        min=temp->value;

        temp=temp->next;
    }

    printf("%d \n",min);

    return min;

}

int min_max_diff_LL(struct Node *head,int min,int max)
{
    return (max-min);
}

void printlist (struct Node* head)
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

    

    int min,max;
    

    max=max_LL(head);


    min=min_LL(head);

    int diff;
    diff=min_max_diff_LL(head,min,max);
    printf("%d",diff);
    printf("\n");

    head=reverse_LL(head);

    printlist(head); 

    




    return 0;
}