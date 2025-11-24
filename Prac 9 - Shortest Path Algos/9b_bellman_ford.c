#include <stdio.h>
#include <limits.h>

#define V 5 // total vertices
#define E 9 // total edges

struct Edge{
    int u, v, w;
};

// Function to print the original graph
void printGraph(struct Edge edges[]){
    printf("Original Graph (Edge List Representation):\n");
    printf("u\tv\tw\n");
    for (int i = 0; i < E; i++){
        printf("%d\t%d\t%d\n", edges[i].u, edges[i].v, edges[i].w);
    }
}

void bellmanFord(struct Edge edges[], int src){
    int dist[V];

    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; i++){
        for (int j = 0; j < E; j++){
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    printf("\nBellman-Ford Output (Shortest Distances from Source %d):\n", src);
    for (int i = 0; i < V; i++){
        printf("Distance to %d = %d\n", i, dist[i]);
    }
}

int main(){
    struct Edge edges[E] = {
        {0, 1, 10}, {0, 2, 3}, {1, 2, 1}, 
        {1, 3, 2}, {2, 1, 4}, {2, 3, 8}, 
        {2, 4, 2}, {3, 4, 7}, {4, 3, 9}
    };

    // Print the original graph
    printGraph(edges);

    bellmanFord(edges, 0); // fucntion calling
    return 0;
}