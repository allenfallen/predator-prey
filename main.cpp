#include "ecosystem/ecosystem.h"
#include "SFML/System/Clock.hpp"
#include "graphLine/graphline.h"

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    ecosystem* e;
    e = new ecosystem(40, 40);
    e->run();
}
