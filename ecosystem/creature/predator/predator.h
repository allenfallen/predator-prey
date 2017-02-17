#ifndef PREDATOR
#define PREDATOR

// Inheritance
#include "../creature.h"
#include "../../abstract/moves/moves.h"
#include "../../abstract/breeds/breeds.h"
#include "../../abstract/dies/dies.h"
#include "../../abstract/eats/eats.h"

// Constants
#define PREDATOR_DEFAULT_HEALTH 10
#define PREDATOR_EAT_COUNT_TO_BREED 30

class predator : public creature, public moves, public eats, public breeds, public dies
{
    public:
        predator(creature*** grid, const coordinate& gridMax, int i = 0, int j = 0);
        predator(creature*** grid, const coordinate& gridMax, const coordinate& position);
        ~predator();

        // Event
        void event();

        // Movement
        void move();
        bool movePolicy();

        // Eating;
        void eat();
        bool eatPolicy();

        // Breed
        void breed();
        bool breedPolicy();
        bool canBreedWith(const coordinate &pos);

        // Death
        void die();
        bool diePolicy();

        // Display
        char face();
        int color();
};

#endif // PREDATOR
