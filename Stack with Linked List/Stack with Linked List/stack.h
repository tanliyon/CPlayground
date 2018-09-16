#ifndef DSTACK
#define DSTACK
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int* data;
  struct node* nextNode;
  } node;

int createStack (node**);
int push (node** , int*);
int pop(node**);
void deleteStack (node**);
void printStack(node**);
#endif
