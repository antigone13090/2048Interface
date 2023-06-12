#include "test.h"

QString Test::init()
{
    grid = (int**) malloc(4*sizeof(int*));
    for(int i=0;i<4;i++)
        grid[i] = (int*) malloc(4*sizeof(int));

    for(int i=0; i<4;i++)
        for(int j=0;j<4;j++)
            grid[i][j]=i+j;
    return QString::number(grid[2][3]);
}

void Test::increment() {
    cptChanged();
}
