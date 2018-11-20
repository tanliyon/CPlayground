#include "graph.h"

#ifdef TEST_GRAPH
Node* createNode (int value)
{
  Node* newNode = malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void addEdge (Graph* graph, int source, int destination, int weight)
{
  int index = source;
  Node* runner = (graph->vertices)[index].head;
  while (runner->next != NULL)
  {
   runner = runner->next;
  }
  runner->next = createNode(destination);
  runner->weight = weight;
}

Graph* createGraph (int* vertices, FILE* inputFile, int numberOfVertices)
{
  Graph* newGraph = malloc(sizeof(Graph));
  newGraph->numberOfVertices = numberOfVertices;
  newGraph->vertices = malloc(numberOfVertices * sizeof(AdjList));

  for (int i=0; i<numberOfVertices; i++)
  {
   (newGraph->vertices)[i].head = createNode(vertices[i]);
  }

  int source;
  int destination;
  int weight;

  while (fscanf(inputFile, "%d", &source) == 1)
  {
    fscanf(inputFile, "%d", &destination);
    fscanf(inputFile, "%d", &weight);
    addEdge(newGraph, source, destination, weight);
  }

  return newGraph;
}

void printGraph (Graph* graph)
{
  for (int i=0; i < graph->numberOfVertices; i++)
  {
    Node* runner = (graph->vertices)[i].head;
    fprintf(stdout, "Vertice %d\n", i+1);
    while (runner != NULL)
    {
      fprintf(stdout, "%d(%d)->", runner->value, runner->weight);
      runner = runner->next;
    }
    fprintf(stdout, "NULL\n\n");
  }
}
#endif

