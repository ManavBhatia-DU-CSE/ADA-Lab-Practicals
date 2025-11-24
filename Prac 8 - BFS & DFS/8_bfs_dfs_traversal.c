#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Globally Declared
int adjMatrix[MAX][MAX];
int visited[MAX];

// NODE STRUCTURE FOR ADJACENCY LIST
struct Node{
    int vertex;
    struct Node *next;
};

struct Node *adjList[MAX];

// QUEUE FOR BFS
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v){
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue(){
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// CREATE NODE
struct Node *createNode(int v){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void BFS(int start, int n){
    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }
    printf("\nBFS Traversal starting from %d: ", start);
    enqueue(start);
    visited[start] = 1;
    while (front <= rear){
        int v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < n; i++){
            if (adjMatrix[v][i] == 1 && !visited[i]){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFS_Util(int v, int n){
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++){
        if (adjMatrix[v][i] == 1 && !visited[i]){
            DFS_Util(i, n);
        }
    }
}

void DFS(int start, int n){
    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }
    printf("\nDFS Traversal starting from %d: ", start);
    DFS_Util(start, n);
    printf("\n");
}

int main(){
    int n, edges, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        adjList[i] = NULL;
        for (int j = 0; j < n; j++){
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++){
        scanf("%d %d", &u, &v);

        // matrix
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

        // list (u → v)
        struct Node *node1 = createNode(v);
        node1->next = adjList[u];
        adjList[u] = node1;

        // list (v → u)
        struct Node *node2 = createNode(u);
        node2->next = adjList[v];
        adjList[v] = node2;
    }

    printf("\nEnter starting node for traversal: ");
    scanf("%d", &start);
    // ADJACENCY MATRIX
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    // ADJACENCY LIST
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++){
        printf("%d -> ", i);
        struct Node *temp = adjList[i];
        while (temp){
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
    // CALL TRAVERSALS
    BFS(start, n);
    DFS(start, n);
    return 0;
}