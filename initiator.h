#ifndef INITIATOR_H
#define INITIATOR_H


class Initiator
{
public:
    Initiator();
    void init(int grid[4][4], int score, int max);
    static int random_index(int x);
};

#endif // INITIATOR_H
