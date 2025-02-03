#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int value;
	struct Node *next;
};

struct Node *appendList(struct Node*,int);
void printList(struct Node*);
struct Node *reverseLimit(struct Node*,int);

int main()
{
	int n;
    int l;
	scanf("%d",&n);

    scanf("%d",&l);

	struct Node *head=NULL;

	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		head=appendList(head,a);
	}

	
    head=reverseLimit(head,l);

	printList(head);



	return 0;
}

struct Node* appendList(struct Node *head,int a)
{
	struct Node *temp=head;
	struct Node *newnode=(struct Node *)malloc (sizeof(struct Node));
	newnode->value=a;
	newnode->next=NULL;

	if(head==NULL)
	{
		return newnode;
	}

	while(temp->next!=NULL)
	{
		temp=temp->next;
	}

	temp->next=newnode;

	return head;
}

void printList(struct Node *head)
{
	struct Node *temp=head;

	while(temp!=NULL)
	{
		if(temp->next==NULL)
		printf("%d",temp->value);

		else
		printf("%d -> ",temp->value);
		
		temp=temp->next;
		

	}

	printf("\n");

	return;


}


struct Node* reverseLimit(struct Node *head,int l)
{    
   
    struct Node *temp=head;
 
    while(temp!=NULL && temp->value!=l)
    {
        temp=temp->next;
       
    }

    struct Node *new=temp->next;


    struct Node *prev=NULL;
    struct Node *current=temp->next;
    struct Node *next=NULL;
    

    while(current!=NULL && current->value!=l)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;

    }  
    
    new->next=current;
    temp->next=prev;
    
    return head;
}


