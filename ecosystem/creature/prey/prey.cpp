#include "prey.h"

prey::prey(creature*** grid, const coordinate &gridMax, int i, int j) : creature(grid, gridMax, i, j)
{
}

prey::prey(creature*** grid, const coordinate &gridMax, const coordinate& pos) : creature(grid, gridMax, pos)
{
}

prey::~prey()
{
}

void prey::event()
{
    if(diePolicy())
        die();

    else if(breedPolicy())
        breed();

    else if(movePolicy())
        move();
}

void prey::move()
{
    // Get position of random neighboring empty space
    coordinate other = getPositionOf(' ');

    // Empy space is occupied by this
    grid[other.row][other.col] = this;

    // Old space is de-occupied
    grid[position.row][position.col] = nullptr;

    // Assign new stat values
    this->position = other;
}

bool prey::movePolicy()
{
    return nextTo(' ');
}

void prey::breed()
{
    // Get coordinate of random neighboring empty space
    coordinate pos = getPositionOf(' ');

    // Miracle of birth
    grid[pos.row][pos.col] = new prey(grid, gridMax, pos);
}

bool prey::breedPolicy()
{
    return nextTo(' ') && (rand()%1000 < PREY_BIRTH_RATE);
}

bool prey::canBreedWith(const coordinate &pos)
{
//    prey* ptr = (prey*)grid[pos.row][pos.col];
//    return this->sex ^ ptr->sex;
}

void prey::die()
{
    delete this;
}

bool prey::diePolicy()
{
    return nextTo('X') && (rand()%1000 < PREY_DEATH_RATE);
}

char prey::face()
{
    return '0';
}

int prey::color()
{
    return 2;
}
