#ifndef DIES_H
#define DIES_H

class dies
{
    public:
        virtual void die() = 0;
        virtual bool diePolicy() = 0;

    protected:
        int health;
};

#endif // DIES_H
