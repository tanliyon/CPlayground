#include "minheap.h"

#ifdef TEST_MINHEAP

HeapNode extractMin(MinHeap* minHeap)
{
  HeapNode minNode = (minHeap->heapArray)[0];
  (minHeap->heapArray)[0] = (minHeap->heapArray)[(minHeap->size)-1];
  minHeapify(minHeap, 0);
  minHeap->size -= 1;
  return minNode;
}

void decreaseKey (MinHeap* minHeap, int verticeIndex, int value)
{
  int minHeapIndex = 0;
  for (int i=0; i<minHeap->size; i++)
  {
    if ((minHeap->heapArray)[i].verticeIndex == verticeIndex)
    {
      minHeapIndex = i;
    }
  }
  
  (minHeap->heapArray)[minHeapIndex].distance = value;
  while (minHeapIndex != 0 && (minHeap->heapArray)[(minHeapIndex-1)/2].distance > (minHeap->heapArray)[minHeapIndex].distance)
  {
    swap(&((minHeap->heapArray)[(minHeapIndex-1)/2]), &((minHeap->heapArray)[minHeapIndex]));
    minHeapIndex = (minHeapIndex-1) / 2;
  }
  return;
}

void minHeapify(MinHeap* minHeap, int index)
{
  int leftChildInd = 2*index + 1;
  int rightChildInd = 2*index + 2;
  int smallestInd = index;
  if (leftChildInd < minHeap->size && (minHeap->heapArray)[leftChildInd].distance < (minHeap->heapArray)[smallestInd].distance)
  {
    smallestInd = leftChildInd;
  }
  if (rightChildInd < minHeap->size && (minHeap->heapArray)[rightChildInd].distance < (minHeap->heapArray)[smallestInd].distance)
  {
    smallestInd = rightChildInd;
  }
  if (smallestInd != index)
  {
    swap(&((minHeap->heapArray)[index]), &((minHeap->heapArray)[smallestInd]));
    minHeapify(minHeap, smallestInd);
  }

  return;
}

void swap (HeapNode* num1, HeapNode* num2)
{
  HeapNode tempHolder = *num1;
  *num1 = *num2;
  *num2 = tempHolder;
  return;
}
#endif
