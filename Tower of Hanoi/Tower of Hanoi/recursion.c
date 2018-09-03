#include "hanoi.h"

void moveDisk(int numberOfDisk, char departurePole, char destinationPole, char extraPole)
{
  // Base case, if you are only moving 1 disk, simply move it
  // from the departurePole to the destinationPole
  if (numberOfDisk == 1)
  {
    fprintf(stdout, "Move from pole %c to pole %c.\n", departurePole, destinationPole);
  }

  else
  {
    // If you numberOfDisk is more than 1, move N-1 disk from departurePole
    // to the extraPole first to make room for the last disk
    moveDisk(numberOfDisk - 1, departurePole, extraPole, destinationPole);
    
    // Once you have enough space, move the largest disk from the departurePole
    // to the destinationPole
    moveDisk(1, departurePole, destinationPole, extraPole);
    
    // Move the remaining N-1 disk from the extra pole to the destinationPole
    moveDisk(numberOfDisk - 1, extraPole, destinationPole, departurePole);
  }

  return;
}
