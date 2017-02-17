#ifndef WALL
#define WALL
#include "../creature.h"

class wall : public creature
{
    public:
        wall(creature*** grid, const coordinate& gridMax, int i = 0, int j = 0);
        wall(creature*** grid, const coordinate& gridMax, const coordinate& pos);

        // Event
        void event();

        // Display
        char face();
        int color();
};
#endif // WALL

