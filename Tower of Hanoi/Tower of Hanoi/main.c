// Include header files
#include "hanoi.h"

int main (int argc, char * * argv)
{
  // Check to make sure 1 number is given as input argument.
  if (argc != 2)
  {
    fprintf(stderr, "Input should be 1 number but %d is given\n", argc - 1);
    return EXIT_FAILURE;
  }
  
  // Take the number of disk and set it to a variable
  int numberOfDisk = (int) strtol (argv[1], NULL, 10);
  
  // Check that the number of disk should be more than 1
  if (numberOfDisk < 1)
  {
    fprintf(stderr, "Input number should be more than 0\n");
    return EXIT_FAILURE;
  }
  
  // Initialize variables ABC for the poles alphabets
  // In this case, we will be having the left pole as Pole A, centre pole
  // as Pole B and right pole as Pole C
  char A = 'A';
  char B = 'B';
  char C = 'C';
  
  // Call the recursive function and end
  moveDisk(numberOfDisk, A, C, B);
  return EXIT_SUCCESS;
}
