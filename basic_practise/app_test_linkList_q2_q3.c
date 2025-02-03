#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

void print_list(struct Node*);
struct Node* add_Element(struct Node*,int);
struct Node* delete_Value(struct Node*,int);
// struct Node* delete_Value_End(struct Node*,int);
struct Node* reverse_Linked_List(struct Node*);

int main()
{
    int n,val; //val is redundant value to be deleted and n is no of elements in linked list
    struct Node *head=NULL;

    scanf("%d",&n);

    scanf("%d",&val);

    

    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        head=add_Element(head,a);
    }

    // delete_Value(head,val);
    // print_list(head);

    head=reverse_Linked_List(head);
    delete_Value(head,val);
    head=reverse_Linked_List(head);
    print_list(head);



    // delete_Value_End(head,val);
    // print_list(head);

    

    
    return 0;
}

struct Node* add_Element(struct Node *head,int a)
{
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->value=a;
    newnode->next=NULL;

    if(head==NULL)
    {
        return newnode;
    }

    struct Node *temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newnode;
    return head;
}
void print_list(struct Node* head)
{
    struct Node *temp=head;
    if(head==NULL)
    {
        printf("empty\n");
    }

    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        temp=temp->next;

    }
    
    
}

struct Node *delete_Value(struct Node *head,int a)
{
    struct Node *prev=head;
    struct Node *start=head;

    while(start->value!=a)
    {
        prev=start;
        start=start->next;
    }

    // struct Node *start=prev->next;

    

    do
    {
        struct Node *temp=start;
        start=start->next;
        prev->next=start;
        free(temp);

    }while(start->value!=a);

    struct Node *temp=start;
    start=start->next;
    prev->next=start;
    free(temp);


    return head;
}

struct Node *reverse_Linked_List(struct Node *head)
{
    struct Node *prev=NULL;
    struct Node *current=head;
    struct Node *next=NULL;

    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;   
        current=next;
    }

    head=prev;
    return head;
}

// struct Node* delete_Value_End(struct Node *head,int a)
// {
//     struct Node *temp=head;
//     int count=0;
//     while(temp!=NULL)
//     {
//         if(temp->value==a)
//         count++;
//         temp=temp->next;
        
//     }

//     printf("%d \n",count);

//     int slast=count-1;

//     struct Node *prev=head;
//     int freq=0;


//     while(freq!=slast)
//     {
//         if(prev->value==a)
//         {
//         freq++;
//         // printf("if run \n");
//         }
//         prev=prev->next;

//         // printf("loop run\n");


//     }

//      printf("%d \n",freq);

//     struct Node *start=prev->next;

//       printf("%d \n",prev->value);

    

//     do
//     {
//         struct Node *temp=start;
//         start=start->next;
//         prev->next=start;
//         free(temp);

//     }while(start->value!=a);

//     return head;
// }