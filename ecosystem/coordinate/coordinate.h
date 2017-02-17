#ifndef MYCOORDINATE
#define MYCOORDINATE

struct coordinate
{
    coordinate(int i = 0, int j = 0);
    coordinate(const coordinate& pos);
    ~coordinate();

    coordinate& operator +=(const coordinate& addMe);
    coordinate& operator =(const coordinate& assignMe);

    friend coordinate operator +(coordinate lhs, coordinate addMe);
    friend bool operator !=(coordinate lhs, coordinate rhs);
    friend bool operator ==(coordinate lhs, coordinate rhs);

    int row, col;
};
#endif // MYCOORDINATE

