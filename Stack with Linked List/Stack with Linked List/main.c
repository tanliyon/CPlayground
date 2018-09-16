#include "stack.h"

int main (int argc,char **argv)
{
  if (argc != 2)
  {
    fprintf(stdout, "Too few input arguments!");
    return EXIT_FAILURE;
  }
  FILE* fptr; 
  fptr = fopen(argv[1], "r");
  if (fptr == NULL) return EXIT_FAILURE;

  int noOfPops;
  fscanf(fptr, "%d", &noOfPops);
  
  int placeholder;
  int count = 0;

  while (!feof(fptr))
  {
    count++;
    fscanf(fptr, "%d", &placeholder);
  }
  count -= 1;
  fseek(fptr, 1, SEEK_SET);

  int* listElement = malloc(count * sizeof(int));

  for (int i = 0; i < count; i++)
  {
    fscanf(fptr, "%d", &listElement[i]);
  }

  node* headerPointer;
  createStack (&headerPointer);

  for (int j = 0; j < count; j++)
  {
    push(&headerPointer, &(listElement[j]));
  } 

  for (int k = 0; k < noOfPops; k++)
  {
    pop(&headerPointer);
  }

  printStack(&headerPointer);
  deleteStack(&headerPointer);

  return EXIT_SUCCESS;
}
