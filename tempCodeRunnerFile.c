void deleteBegin(struct Node** head)
{
    struct Node* temp=*head;
    temp=temp->next;
    *head=temp;
    free(temp);

}