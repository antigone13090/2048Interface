#include "backuper.h"
#include<stdlib.h>
#include<stdio.h>

Backuper::Backuper(){}
/* save the last grid
   using on the method logic_flow*/

void Backuper::backup_grid(int bgrid[4][4], int grid[4][4]) { // method to save the last grid in bgrid
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            bgrid[i][j]=grid[i][j];
}
