#include <stdio.h>
#define MAX 100 // Maximum number of vertices

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int vertex)
{
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = vertex;
    }
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// BFS Function
void bfs(int adj[MAX][MAX], int n, int start)
{
    int visited[MAX] = {0};
    int i, v;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal starting from vertex %d: ", start);

    while (front <= rear)
    {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Main Function
int main()
{
    int adj[MAX][MAX], n, start;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(adj, n, start);

    return 0;
}
