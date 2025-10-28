#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL; // Head pointer to start of the list

// Function to insert a new node at the end
void insertNode()
{
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    // Create a new node directly here
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        // Traverse to the end of the list
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // Link new node to last node
        temp->next = newNode;
    }
    printf("Node inserted successfully!\n");
}

// Function to delete a node by value
void deleteNode()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);

    struct Node *temp = head, *prev = NULL;

    // If node to be deleted is the head node
    if (temp != NULL && temp->data == value)
    {
        head = temp->next;
        free(temp);
        printf("Node deleted successfully!\n");
        return;
    }

    // Traverse to find the node
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    // If not found
    if (temp == NULL)
    {
        printf("Value not found in list!\n");
        return;
    }

    // Unlink and free the node
    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully!\n");
}

// Function to display the list
void displayList()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to count total nodes
void countNodes()
{
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Total number of nodes: %d\n", count);
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Count Nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertNode();
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            displayList();
            break;
        case 4:
            countNodes();
            break;
        case 5:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
