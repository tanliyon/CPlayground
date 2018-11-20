#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adjNode
{
  int value;
  int weight;
  struct adjNode* next;
} Node;

typedef struct adjlist
{
  Node* head;
} AdjList;

typedef struct graph
{
  int numberOfVertices;
  AdjList* vertices;
  int* weights;
} Graph;

void printGraph (Graph*);
void addEdge (Graph*, int, int, int);
Graph* createGraph(int*, FILE*, int);
Node* createNode (int);
