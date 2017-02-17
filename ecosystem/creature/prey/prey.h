#ifndef PREY
#define PREY

// Inheritance
#include "../creature.h"
#include "../../abstract/moves/moves.h"
#include "../../abstract/breeds/breeds.h"
#include "../../abstract/dies/dies.h"

// Constants
#define PREY_BIRTH_RATE 660
#define PREY_DEATH_RATE 450

class prey : public creature, public moves, public breeds, public dies
{
    public:
        prey(creature*** grid, const coordinate& gridMax, int i = 0, int j = 0);
        prey(creature*** grid, const coordinate& gridMax, const coordinate& pos);
        ~prey();

        // Event
        void event();

        // Movement
        void move();
        bool movePolicy();

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

#endif // PREY

