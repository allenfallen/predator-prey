#ifndef CREATURE
#define CREATURE

// Nullptr
#include <stdio.h>
#include <stdlib.h>

// RNG
#include <random>

// Coordinate
#include "../coordinate/coordinate.h"

class creature
{
    public:
        creature(creature*** grid, const coordinate& gridMax, int i = 0, int j = 0);
        creature(creature*** grid, const coordinate& gridMax, const coordinate& position);
        ~creature();

        // Event
        virtual void event();

        // Check surroundings for specific creature within radius len
        bool nextTo(char face, int radius = 1);

        // NOTE: Using this function assumes the nextTo function has returned true
        coordinate getPositionOf(char face, int radius = 1);

        // Display
        virtual char face();
        virtual int color();

        // RNG
        inline unsigned int rand()
        {
            return dist(rd);
        }

    protected:
        coordinate position;
        creature*** grid;
        coordinate gridMax;

        // RNG
        std::random_device rd;
        std::uniform_int_distribution<int> dist;
};


#endif // CREATURE

