#include <stdio.h>
#include <limits.h>

#define V 5

// Function to print the adjacency matrix (original graph)
void printGraph(int graph[V][V]){
    printf("Original Graph (Adjacency Matrix):\n");
    printf("     0  1  2  3  4\n");

    for (int i = 0; i < V; i++){
        printf("%d | ", i);
        for (int j = 0; j < V; j++){
            printf("%2d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Returns vertex with minimum distance among unvisited vertices
int minDistance(int dist[], int visited[]){
    int min = INT_MAX, index = -1;
    for (int i = 0; i < V; i++){
        if (!visited[i] && dist[i] <= min){
            min = dist[i];
            index = i;
        }
    }

    return index;
}

void dijkstraArray(int graph[V][V], int src){
    int dist[V], visited[V];
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++){
        int u = minDistance(dist, visited);
        if (u == -1) break;
        visited[u] = 1;
        for (int v = 0; v < V; v++){
            if (!visited[v] && graph[u][v] &&dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Dijkstra (Array/Linear Search) Output:\n");
    for (int i = 0; i < V; i++){
        printf("Distance to %d = %d\n", i, dist[i]);
    }
}

int main(){
    int graph[V][V] = {
        {0, 10, 3, 0, 0},
        {0, 0, 1, 2, 0},
        {0, 4, 0, 8, 2},
        {0, 0, 0, 0, 7},
        {0, 0, 0, 9, 0}
    };

    // Print original graph
    printGraph(graph);

    dijkstraArray(graph, 0); // function calling
    return 0;
}