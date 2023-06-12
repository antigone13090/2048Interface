#include "largetscorechecker.h"

LargetScoreChecker::LargetScoreChecker(){}
/*  use to get the largest score (or integer) of the 16 cases of the grid*/

void LargetScoreChecker::plusGrandeCase(int grid[4][4], int* max) { // method to get the largest score of the 16 cases of the array grid and to put it on the variable max
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(grid[i][j]> *(max))
                *(max)=grid[i][j];
}
