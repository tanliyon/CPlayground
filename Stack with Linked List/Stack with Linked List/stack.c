#include "stack.h"

int createStack (node** headPointer)
{
  *headPointer = NULL;
  return 1;
}

int push (node** headPointer, int* data)
{
  node* newNode = malloc(sizeof(node));
  if (newNode == NULL) return EXIT_FAILURE;

  newNode->data = data;
  newNode->nextNode = (struct node*) *headPointer;
  *headPointer = newNode;
  return 1;
}

int pop (node** headPointer)
{
  node* tempPointer = *headPointer;
  if (tempPointer == NULL) return EXIT_FAILURE;
  
  *headPointer = (node*) tempPointer->nextNode;
  free(tempPointer);
  return 1;
}

void printStack(node** headPointer)
{
  node* tempPointer = *headPointer;
  while (tempPointer->nextNode != NULL)
  {
    fprintf(stdout, "%d\n", *(tempPointer->data));
    tempPointer = (node*) tempPointer->nextNode;
  }
  fprintf(stdout, "%d\n", *(tempPointer->data));
  return;
}

void deleteStack (node** headPointer)
{
  node* tempPointer = *headPointer;
  while (tempPointer->nextNode != NULL)
  {
    *headPointer = (node*) tempPointer->nextNode;
    free(tempPointer);
    tempPointer = *headPointer;
  }
  free(tempPointer);
  return;
}
