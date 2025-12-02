#include <stdio.h> // Standard input/output functions

#define MAX 20 // Maximum number of elements allowed

int parent[MAX];   // Array to store the parent for each element (for union-find)
int elements[MAX]; // Array to store actual user input elements
int n;             // Number of elements

// Function to create disjoint sets
void createSet()
{
    printf("Enter number of elements (max %d): ", MAX); // Ask how many elements
    scanf("%d", &n);                                    // Read number of elements

    printf("Enter %d elements: ", n); // Prompt to enter elements
    for (int i = 0; i < n; i++)       // Loop through each element
    {
        scanf("%d", &elements[i]); // Read element into array
        parent[i] = i;             // Initially, each element is its own parent
    }
    printf("Disjoint sets created.\n");
}

// Find index of given element in the elements[] array
int getIndex(int x)
{
    for (int i = 0; i < n; i++) // Loop through all elements
    {
        if (elements[i] == x) // If element matches user input
            return i;         // Return index
    }
    return -1; // Element not found
}

// Find the root representative with path compression
int findSet(int i)
{
    if (parent[i] != i)                 // If element is not its own parent
        parent[i] = findSet(parent[i]); // Recursively find root and compress path
    return parent[i];                   // Return final representative
}

// Union operation to merge two sets
void unionSet(int x, int y)
{
    int i = getIndex(x); // Find index of x in elements[]
    int j = getIndex(y); // Find index of y in elements[]

    if (i == -1 || j == -1) // If either element not found
    {
        printf("One or both elements not found!\n");
        return;
    }

    int rootI = findSet(i); // Find representative of x
    int rootJ = findSet(j); // Find representative of y

    if (rootI != rootJ) // If they belong to different sets
    {
        parent[rootJ] = rootI; // Make root of J point to root of I (union)
        printf("Union done: %d and %d are now in the same set.\n", x, y);
    }
    else
    {
        printf("%d and %d are already in the same set.\n", x, y);
    }
}

// Display parent mapping for debugging
void display()
{
    printf("Element: ");
    for (int i = 0; i < n; i++)
        printf("%d ", elements[i]); // Print actual elements

    printf("\nParent : ");
    for (int i = 0; i < n; i++)
        printf("%d ", elements[parent[i]]); // Print their parent elements
    printf("\n");
}

int main()
{
    int choice, x, y; // Variables for menu choice & user input

    createSet(); // Create initial disjoint sets

    do
    {
        printf("\n--- Disjoint Set Operations ---\n");
        printf("1. Union\n");   // Menu for union
        printf("2. Find\n");    // Menu for find
        printf("3. Display\n"); // Menu for display
        printf("4. Exit\n");    // Exit
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) // Based on choice perform action
        {
        case 1:
            printf("Enter two elements to union: ");
            scanf("%d %d", &x, &y); // Take two elements
            unionSet(x, y);         // Call union operation
            break;

        case 2:
            printf("Enter element to find its set representative: ");
            scanf("%d", &x); // Enter element for find
            {
                int idx = getIndex(x); // Get index of element
                if (idx == -1)
                    printf("Element not found!\n");
                else
                    printf("Representative of %d is: %d\n",
                           x, elements[findSet(idx)]); // Print representative
            }
            break;

        case 3:
            display(); // Display mapping
            break;

        case 4:
            printf("Exiting...\n"); // End program
            break;

        default:
            printf("Invalid choice!\n"); // Wrong input case
        }
    } while (choice != 4); // Loop until exit

    return 0;
}
