#include "prey.h"

prey::prey(creature*** grid, const coordinate &gridMax, int i, int j) : creature(grid, gridMax, i, j)
{
    health = PREY_DEFAULT_HEALTH;
    steps = 0;
    sex = rand()%2;
}

prey::prey(creature*** grid, const coordinate &gridMax, const coordinate& pos) : creature(grid, gridMax, pos)
{
    health = PREY_DEFAULT_HEALTH;
    steps = 0;
    sex = rand()%2;
}

prey::~prey()
{
    health = steps = sex = NULL;
}

void prey::event()
{
    if(diePolicy())
        die();

    else if(breedPolicy())
        breed();

    else if(movePolicy())
        move();

    else
        health--;
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
    position = other;
    steps++;
}

bool prey::movePolicy()
{
    return nextTo(' ') && rand()%10 < 9;
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
    return nextTo(' ') && steps && !(steps % PREY_STEPS_TO_BREED);
//    if(nextTo('0'))
//    {
//        coordinate posOfMate = getPositionOf('0');
//        return canBreedWith(posOfMate) && nextTo(' ') && steps && !(steps % PREY_STEPS_TO_BREED);
//    }
//    return false;
}

bool prey::canBreedWith(const coordinate &pos)
{
    prey* ptr = (prey*)grid[pos.row][pos.col];
    return this->sex ^ ptr->sex;
}

void prey::die()
{
    delete this;
}

bool prey::diePolicy()
{
    return health < 0;
}

char prey::face()
{
    return '0';
}

int prey::color()
{
    return 2;
}
