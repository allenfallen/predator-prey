#include "predator.h"

predator::predator(creature*** grid, const coordinate &gridMax, int i, int j) : creature(grid, gridMax, i, j)
{
}

predator::predator(creature*** grid, const coordinate &gridMax, const coordinate& position) : creature(grid, gridMax, position)
{
}

predator::~predator()
{
}

void predator::event()
{
    if(breedPolicy())
        breed();

    else if(eatPolicy())
        eat();

    else if(diePolicy())
      die();

    else if(movePolicy())
        move();
}

void predator::move()
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

bool predator::movePolicy()
{
    return nextTo(' ');
}

void predator::eat()
{
    // Get coordinate of random neighboring prey
    coordinate posOfPrey = getPositionOf('0');

    // Delete prey
    delete grid[posOfPrey.row][posOfPrey.col];
    grid[posOfPrey.row][posOfPrey.col] = nullptr;
}

bool predator::eatPolicy()
{
    return nextTo('0');
}

void predator::breed()
{
    // Get position of random neighboring prey
    coordinate posOfPrey = getPositionOf('0');

    // Delete prey
    delete grid[posOfPrey.row][posOfPrey.col];

    // Miracle of birth
    grid[posOfPrey.row][posOfPrey.col] = new predator(grid, gridMax, posOfPrey);
}

bool predator::breedPolicy()
{
    return nextTo('0') && (rand()%1000 < PREDATOR_BIRTH_RATE);
}

bool predator::canBreedWith(const coordinate &pos)
{
//    predator* ptr = (predator*)grid[pos.row][pos.col];
//    return this->sex ^ ptr->sex;
}

void predator::die()
{
    delete this;
}

bool predator::diePolicy()
{
    return rand()%1000 < PREDATOR_DEATH_RATE;
}

char predator::face()
{
    return 'X';
}

int predator::color()
{
    return 3;
}
