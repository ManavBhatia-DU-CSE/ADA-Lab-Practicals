#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge{
    int src, dest, weight;
};

// Structure for the graph
struct Graph{
    int V, E;
    struct Edge *edge;
};

// Subset for Union-Find
struct Subset{
    int parent;
    int rank;
};

struct Graph *createGraph(int V, int E){
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge *)malloc(E * sizeof(struct Edge));
    return graph;
}

// Find with path compression
int find(struct Subset subsets[], int i){
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union by rank
void Union(struct Subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparator for qsort
int compare(const void *a, const void *b){
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

void KruskalMST(struct Graph *graph){
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

    for (int v = 0; v < V; ++v){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E){
        struct Edge next = graph->edge[i++];
        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);
        if (x != y){
            result[e++] = next;
            Union(subsets, x, y);
        }
    }

    printf("Edge\tWeight\n");
    int totalWeight = 0;

    for (i = 0; i < e; ++i){
        printf("%d - %d\t%d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }

    printf("Total weight of MST: %d\n", totalWeight);
    free(subsets);
}

int main(){
    int V = 5;
    // Total edges from adjacency matrix = 7
    int E = 7;
    struct Graph *graph = createGraph(V, E);
    graph->edge[0] = (struct Edge){0, 1, 2};
    graph->edge[1] = (struct Edge){0, 3, 6};
    graph->edge[2] = (struct Edge){1, 2, 3};
    graph->edge[3] = (struct Edge){1, 3, 8};
    graph->edge[4] = (struct Edge){1, 4, 5};
    graph->edge[5] = (struct Edge){2, 4, 7};
    graph->edge[6] = (struct Edge){3, 4, 9};
    KruskalMST(graph);
    free(graph->edge);
    free(graph);
    return 0;
}
