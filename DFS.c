#include <stdio.h>
#define MAX 10

int visited[MAX];
int graph[MAX][MAX];
int n; // Number of vertices


void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; 
    }
    
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int startVertex;
    printf("Enter starting vertex: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal: ");
    DFS(startVertex);

    return 0;
}
