#include <stdio.h>
#include <stdlib.h>
struct Node{
    int value;
    struct Node *next;
};

void print_list(struct Node*);
struct Node* add_Element(struct Node*,int);
struct Node* reverse_Linked_List(struct Node*);
void delete_group(int,struct Node**);

int main()
{
     int n,val; //val is group size to be deleted and n is no of elements in linked list
    struct Node *head=NULL;

    scanf("%d",&n);

    scanf("%d",&val);

    

    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        head=add_Element(head,a);
    }   

    delete_group(val,&head);
    print_list(head);



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
// struct Node *reverse_Linked_List(struct Node *head)
// {

// }

void delete_group(int n,struct Node** head)
{
    struct Node* temp= *head;
    int count=0;
    while((temp)!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("count: %d\n",count);

    int group=count/n;

    struct Node *prev=NULL;
    struct Node *current=*head;
    struct Node *next=NULL;
    struct Node *start=NULL;
        start=*head;
        temp=*head;

    for(int i=0;i<group;i++)
    {
        for(int j=0;j<n;j++)
        {
            (next)=(current)->next;
            (current)->next=(prev);
            (prev)=(current);
            (current)=(next);
        }     

       if(i==0) *head=prev;    //for head change
       temp=start;  
       temp->next=prev; 
       start=current;
       prev=NULL;               //re initilisiation of var for group change
       current=start;          //re initilisiation of var for group change
       next=NULL;              //re initilisiation of var for group change

    }









    


}