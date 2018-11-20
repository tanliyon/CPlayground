#include "graph.h"

typedef struct heapnode
{
  int distance;
  int verticeIndex;
} HeapNode;

typedef struct minheap
{
  int size;
  HeapNode* heapArray;
}MinHeap;

void minHeapify(MinHeap*, int);
HeapNode extractMin(MinHeap*);
void decreaseKey(MinHeap*, int, int);
void swap(HeapNode*, HeapNode*);
