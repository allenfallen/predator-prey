#include "wall.h"

wall::wall(creature*** grid, const coordinate& gridMax, int i, int j) : creature(grid, gridMax, i, j)
{
}

wall::wall(creature*** grid, const coordinate &gridMax, const coordinate& pos) : creature(grid, gridMax, pos)
{
}

void wall::event()
{
    // Walls don't do anything
}

char wall::face()
{
    return '*';
}

int wall::color()
{
    return 0;
}
