#ifndef MOVES_H
#define MOVES_H

class moves
{
    public:
        virtual void move() = 0;
        virtual bool movePolicy() = 0;

    protected:
        unsigned int steps;
};

#endif // MOVES_H
