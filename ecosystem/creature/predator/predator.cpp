#include "predator.h"

predator::predator(creature*** grid, const coordinate &gridMax, int i, int j) : creature(grid, gridMax, i, j)
{
    health = PREDATOR_DEFAULT_HEALTH;
    steps = 0;
    eatCount = 0;
    sex = rand()%2;
}

predator::predator(creature*** grid, const coordinate &gridMax, const coordinate& position) : creature(grid, gridMax, position)
{
    health = PREDATOR_DEFAULT_HEALTH;
    steps = 0;
    eatCount = 0;
    sex = rand()%2;
}

predator::~predator()
{
    health = NULL;
    steps = eatCount = sex = 0;
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

    else
        health--;
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
    position = other;
    health -= 2;
    steps++;

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

    // Assign new stat values
    health += 2;
    eatCount++;
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

    // Assign new stat values
    health--;
}

bool predator::breedPolicy()
{
    return nextTo('0') && eatCount && !(eatCount % PREDATOR_EAT_COUNT_TO_BREED);

//    if(nextTo('X'))
//    {
//        coordinate posOfMate = getPositionOf('X');
//        return canBreedWith(posOfMate) && nextTo('0') && eatCount && !(eatCount % PREDATOR_EAT_COUNT_TO_BREED);
//    }
//    return false;
}

bool predator::canBreedWith(const coordinate &pos)
{
    if(nextTo('X'))
    {
    predator* ptr = (predator*)grid[pos.row][pos.col];
    return this->sex ^ ptr->sex;
    }
}

void predator::die()
{
    delete this;
}

bool predator::diePolicy()
{
    return health < 0;
}

char predator::face()
{
    return 'X';
}

int predator::color()
{
    return 3;
}
