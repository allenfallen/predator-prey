#ifndef EATS_H
#define EATS_H

class eats
{
    public:
        virtual void eat() = 0;
        virtual bool eatPolicy() = 0;

    protected:
        unsigned int eatCount;
};

#endif // EATS_H
