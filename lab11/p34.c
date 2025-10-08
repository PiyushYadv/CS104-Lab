#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
struct Node
{
  int data;
  struct Node *next;
};

// Structure to represent the graph
struct Graph
{
  int numVertices;
  struct Node **adjLists;
  int *visited;
};

// Function to create a new graph with given number of vertices
struct Graph *createGraph(int vertices)
{
  struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  // Create an array of adjacency lists, one for each vertex
  graph->adjLists = (struct Node **)malloc(vertices * sizeof(struct Node *));

  // Initialize each adjacency list as empty by making each head pointer NULL
  for (int i = 0; i < vertices; ++i)
    graph->adjLists[i] = NULL;

  // Create an array to keep track of visited vertices, initialized as 0 (unvisited)
  graph->visited = (int *)malloc(vertices * sizeof(int));
  for (int i = 0; i < vertices; ++i)
    graph->visited[i] = 0;

  return graph;
}

// Function to create a new node
struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
  // Add edge from src to dest
  struct Node *newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Since the graph is undirected, add an edge from dest to src as well
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

// Function to perform Depth First Search traversal
void DFS(struct Graph *graph, int vertex)
{
  // Mark the current vertex as visited
  graph->visited[vertex] = 1;
  printf("%d ", vertex);

  // Recursively visit all the adjacent vertices
  struct Node *temp = graph->adjLists[vertex];
  while (temp != NULL)
  {
    int adjVertex = temp->data;
    if (graph->visited[adjVertex] == 0)
      DFS(graph, adjVertex);
    temp = temp->next;
  }
}

// Function to perform Breadth First Search traversal
void BFS(struct Graph *graph, int startVertex)
{
  // Initialize a queue for BFS
  int queue[graph->numVertices];
  int front = 0, rear = -1;

  // Enqueue the start vertex and mark it as visited
  queue[++rear] = startVertex;
  graph->visited[startVertex] = 1;

  // Loop until the queue is empty
  while (front <= rear)
  {
    // Dequeue a vertex from the queue and print it
    int currentVertex = queue[front++];
    printf("%d ", currentVertex);

    // Enqueue all adjacent vertices of the dequeued vertex that are not visited yet
    struct Node *temp = graph->adjLists[currentVertex];
    while (temp != NULL)
    {
      int adjVertex = temp->data;
      if (graph->visited[adjVertex] == 0)
      {
        queue[++rear] = adjVertex;
        graph->visited[adjVertex] = 1;
      }
      temp = temp->next;
    }
  }
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph *graph)
{
  for (int v = 0; v < graph->numVertices; ++v)
  {
    struct Node *temp = graph->adjLists[v];
    printf("\nAdjacency list of vertex %d\n", v);
    while (temp)
    {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

// Test program
int main()
{
  printf("Piyush Yadav - 23/CS/301\n");

  int numVertices = 5;
  struct Graph *graph = createGraph(numVertices);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);

  printf("Graph representation:\n");
  printGraph(graph);

  printf("\nDFS traversal starting from vertex 0:\n");
  DFS(graph, 0);

  // Resetting visited array for BFS traversal
  for (int i = 0; i < numVertices; ++i)
    graph->visited[i] = 0;

  printf("\n\nBFS traversal starting from vertex 0:\n");
  BFS(graph, 0);

  return 0;
}
