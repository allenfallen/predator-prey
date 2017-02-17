#include "coordinate.h"

coordinate::coordinate(int i, int j)
{
    row = i;
    col = j;
}

coordinate::coordinate(const coordinate &pos)
{
    row = pos.row;
    row = pos.col;
}

coordinate::~coordinate()
{
    row = col = 0;
}

coordinate operator +(coordinate lhs, coordinate rhs)
{
    return coordinate(lhs.row + rhs.row, lhs.col + rhs.col);
}

coordinate& coordinate::operator +=(const coordinate& addMe)
{
    row += addMe.row;
    col += addMe.col;
    return *this;
}

coordinate& coordinate::operator =(const coordinate& assignMe)
{
    row = assignMe.row;
    col = assignMe.col;
    return *this;
}

bool operator !=(coordinate lhs, coordinate rhs)
{
    return (lhs.row != rhs.row || lhs.col != rhs.col);
}

bool operator ==(coordinate lhs, coordinate rhs)
{
    return lhs.row == rhs.row && lhs.col == rhs.col;
}




