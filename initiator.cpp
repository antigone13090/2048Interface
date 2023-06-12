#include "initiator.h"
#include<stdlib.h>

Initiator::Initiator(){}
/* using to initialize the variables:  grid, score and max
   (all cases have values 0 exept 2 cases with value 2)
   and using to get an integer between 0 and x-1*/

void Initiator::init(int grid[4][4], int score, int max) { // method to initialize the 3 variables passed in parameters
    int i,j;

    score=0;
    max=0;
    for(i=0;i<4;i++)      // initialize the grid with the value 0
        for(j=0;j<4;j++)
            grid[i][j]=0;

    i=random_index(4);   // choose the first case with the value 2
    j=random_index(4);
    grid[i][j]=2;

    do                                     // choose the second case with the value 2
    {
        i=random_index(4);
        j=random_index(4);
    }while(grid[i][j]!=0);  // repeat until the cell is different of 0

    grid[i][j]=2;
}

int Initiator::random_index(int x) {    // method to get an integer between 0 and x-1
    int index;
    index=rand()%x+0;

    return index;
}
