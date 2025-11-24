#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5

struct Node{
    int vertex, dist;
};

struct MinHeap{
    int size;
    struct Node *arr[V * V];
};

// Graph Printing
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

//  Min Heap Utility 
struct Node *newNode(int v, int d){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->vertex = v;
    temp->dist = d;
    return temp;
}

void swap(struct Node **a, struct Node **b){
    struct Node *t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct MinHeap *h, int i){
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    if (left < h->size && h->arr[left]->dist < h->arr[smallest]->dist)
        smallest = left;

    if (right < h->size && h->arr[right]->dist < h->arr[smallest]->dist)
        smallest = right;

    if (smallest != i){
        swap(&h->arr[i], &h->arr[smallest]);
        heapify(h, smallest);
    }
}

struct Node *extractMin(struct MinHeap *h){
    if (h->size <= 0)  return NULL;

    struct Node *root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

void insertHeap(struct MinHeap *h, struct Node *node){
    int i = h->size++;
    h->arr[i] = node;

    while (i != 0 && h->arr[(i - 1) / 2]->dist > h->arr[i]->dist){
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Dijkstra (Min-Heap)
void dijkstraHeap(int graph[V][V], int src){
    int dist[V];
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
    }

    struct MinHeap h;
    h.size = 0;
    dist[src] = 0;
    insertHeap(&h, newNode(src, 0));

    while (h.size > 0){
        struct Node *minNode = extractMin(&h);
        if (!minNode)  break; // safety check
        int u = minNode->vertex;
        for (int v = 0; v < V; v++){
            if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
                insertHeap(&h, newNode(v, dist[v]));
            }
        }
    }

    printf("Dijkstra (Min-Heap/Priority Queue) Output:\n");
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
        {0, 0, 0, 9, 0}};

    // Print original graph
    printGraph(graph);

    dijkstraHeap(graph, 0); // function calling
    return 0;
}