#include "main.h"

#ifdef TEST_MAIN
int main (int argc, char** argv)
{
  if (argc < 2)
  {
    return EXIT_FAILURE;
  }

  FILE* inputFile = fopen(argv[1], "r");

  int numberOfVertices;
  fscanf(inputFile, "%d", &numberOfVertices);
  int* vertices = malloc(numberOfVertices * sizeof(int));

  for (int i=0; i<numberOfVertices; i++)
  {
    fscanf(inputFile, "%d", &vertices[i]);
  }
  Graph* graph = createGraph(vertices, inputFile, numberOfVertices);
  printGraph(graph);

  dijikstra(graph, numberOfVertices, 0);

  fclose(inputFile);

  return EXIT_SUCCESS;
}
#endif

#ifdef TEST_DIJIKSTRA

void dijikstra(Graph* graph, int numberOfVertices, int source)
{
  // Initialize
  int* distanceArray = malloc(numberOfVertices * sizeof(int));
  int* predecessor = malloc(numberOfVertices * sizeof(int));
  MinHeap* minHeap = malloc(sizeof(MinHeap));
  minHeap->heapArray = malloc(numberOfVertices * sizeof(HeapNode));
  minHeap->size = numberOfVertices;
  for (int i=0; i<numberOfVertices; i++)
  {
    (minHeap->heapArray)[i].distance = 99;
    (minHeap->heapArray)[i].verticeIndex = i;
    distanceArray[i] = 99;
  }
  (minHeap->heapArray)[source].distance = 0;
  distanceArray[source] = 0;
  swap(&((minHeap->heapArray)[source]), &((minHeap->heapArray)[0]));

  
  // Start looping through the vertices
  while (minHeap->size > 0)
  {
    HeapNode minNode = extractMin(minHeap);
    int verticeDistance = minNode.distance;
    int verticeIndex = minNode.verticeIndex;
    AdjList exploreVertice = (graph->vertices)[verticeIndex];
    relax(exploreVertice, verticeDistance, minHeap, distanceArray, predecessor);
  }

  // Print Shortest Path
  for (int i=0; i<numberOfVertices; i++)
  {
    fprintf(stdout, "Shortest Path from vertice %d to vertice %d\n", source, i); 
    int endingPoint = i;
    while (endingPoint != source && distanceArray[i] != 99)
    {
      fprintf(stdout, "%d<-", endingPoint);
      endingPoint = predecessor[endingPoint];
    }
    fprintf(stdout, "%d\ndistance: %d\n\n", source, distanceArray[i]);
  }
  return;
}

void relax(AdjList vertice, int verticeDistance, MinHeap* minHeap, int* distanceArray, int* predecessor)
{
  Node* runner = vertice.head;
  while (runner->next != NULL)
  {
    int decreasedDistance = verticeDistance + runner->weight;
    int index = (runner->next)->value;

    if (decreasedDistance < distanceArray[index])
    {
      decreaseKey(minHeap, index, decreasedDistance);
      distanceArray[index] = decreasedDistance;
      predecessor[index] = (vertice.head)->value;
    }
    runner = runner->next;
  }
}

#endif
