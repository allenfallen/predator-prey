#ifndef ECOSYSTEM
#define ECOSYSTEM

// Curses library
#include <ncurses.h>
#include <unistd.h>

// Graph
#include "graphLine/graphline.h"

// Ecosystem inhabitants
#include "creature/creature.h"
#include "creature/predator/predator.h"
#include "creature/prey/prey.h"
#include "creature/wall/wall.h"

// RNG
#include <random>

class ecosystem
{
    public:
        ecosystem(const int i = 40, const int j = 40);
        ~ecosystem();

        // Run simulation
        void run();

        // Resize the grid
        void resize(int i, int j);

    private:
        // Grid
        creature*** grid;
        coordinate gridMax;
        bool hasColor;

        // Graph
        graphLine* graph;

        // Grid functions
        void createGrid();
        void loadGrid();
        void deleteGrid();

        // Spawn creature randomly on the grid
        void spawn(char face, int population);

        // Call events of all inhabitants of the ecosystem
        void event();

        // Print grid to terminal
        void printGrid();

        // Population count of the whole ecosystem
        int count();

        // Population count of a particular kind of creature
        int count(char face);

        // Whether a coordinate on the grid is occupied by a creature
        inline bool isOccupied(int i, int j)
        {
            return grid[i][j];
        }

        // Duration of simulation
        sf::Clock durationClock;
        sf::Time durationTime;

        // RNG
        std::random_device rd;
        std::uniform_int_distribution<int> dist;
};

#endif // ECOSYSTEM

