#ifndef BREEDS_H
#define BREEDS_H

#include "../../coordinate/coordinate.h"

class breeds
{
    public:
        virtual void breed() = 0;
        virtual bool breedPolicy() = 0;

        // TODO: Implement biological sex and require two neighboring creatures of the same kind to breed
        virtual bool canBreedWith(const coordinate& pos) = 0;

        inline bool getSex()
        {
            return sex;
        }

    protected:
        bool sex;
};


#endif // BREEDS_H
