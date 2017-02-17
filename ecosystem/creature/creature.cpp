#include "creature.h"

creature::creature(creature*** grid, const coordinate &gridMax, int i, int j)
{
    this->grid = grid;
    this->gridMax = gridMax;
    this->position = coordinate(i, j);
}

creature::creature(creature*** grid, const coordinate &gridMax, const coordinate& position)
{
    this->grid = grid;
    this->gridMax = gridMax;
    this->position = position;
}

creature::~creature()
{
    // Remove self from grid
    grid[position.row][position.col] = nullptr;
    grid = nullptr;
}

void creature::event()
{
}

bool creature::nextTo(char face, int radius)
{
    // Get surrounding area within length of len
    for(int i = position.row - radius; i < position.row + radius + 1; i++)
        for(int j = position.col - radius; j < position.col + radius + 1; j++)

            // Within boundaries of the grid
            if(i >= 0 && j >= 0 && i < gridMax.row && j < gridMax.col)

                // Meets face requirement
                if((!grid[i][j] && face == ' ') || grid[i][j] && grid[i][j]->face() == face)
                    return true;
    return false;
}

coordinate creature::getPositionOf(char face, int radius)
{
    // 8 possible movement directions
    coordinate list[8];
    int index = 0;

    // Get surrounding area within length of len
    for(int i = position.row - radius; i < position.row + radius + 1; i++)
        for(int j = position.col - radius; j < position.col + radius + 1; j++)

            // Within boundaries of the grid
            if(i >= 0 && j >= 0 && i < gridMax.row && j < gridMax.col)

                // Meets face requirement
                if((!grid[i][j] && face == ' ') || (grid[i][j] && grid[i][j]->face() == face))
                {
                    list[index] = coordinate(i, j);
                    index++;
                }

    // Randomly select a coordinate in the list
    index = (dist(rd))%(index);
    return coordinate(list[index].row, list[index].col);
}

char creature::face()
{
    return '?';
}

int creature::color()
{
    return 0;
}
