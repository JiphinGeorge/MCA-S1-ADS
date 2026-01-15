#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

createNode(int value )
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(value){
    struct Node *newNode = createNode(value);
    if(head== NULL){
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(value){
   
    if(head==NULL){
        printf("The lit is empty");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    if(head->data==value)
    {

        head = head->next;
        free(temp);
        return;
    }

    while(temp->data!=value && temp!=NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL)
    {
        printf("Value not found");

    }
    prev->next = temp->next;
    free(temp);

    
}

void displayList(){
    if(head==NULL)
    {
        printf("The list is Empty !");
        return;
    }
    struct Node *temp = head;

    printf("List:");
    while(temp!=NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
}

void countNodes(){
    if(head==NULL)
    {
        printf("0");
        return;
    }
    int count = 0;
    struct Node *temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;

    }
    printf("the total count is  %d", count);
}
int main()
{
    int ch, value;
    while (1)
    {
        printf("\n1.Insert Node \2,delete Node \n33.display \n4.Count \n 5.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value to insert :");
            scanf("%d", &value);
            insertNode(value);
            break;
        case 2:
            printf("Enter the value to delete :");
            scanf("%d", &value);
            deleteNode(value);
            break;
        case 3:
            displayList();
            break;
        case 4:
            countNodes();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}