TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    graphLine/graphline.cpp \
    ecosystem/coordinate/coordinate.cpp \
    ecosystem/ecosystem.cpp \
    ecosystem/creature/creature.cpp \
    ecosystem/creature/predator/predator.cpp \
    ecosystem/creature/prey/prey.cpp \
    ecosystem/creature/wall/wall.cpp \

HEADERS += \
    graphLine/graphline.h \
    ecosystem/coordinate/coordinate.h \
    ecosystem/ecosystem.h \
    ecosystem/creature/creature.h \
    ecosystem/creature/predator/predator.h \
    ecosystem/creature/prey/prey.h \
    ecosystem/creature/wall/wall.h \
    ecosystem/abstract/moves/moves.h \
    ecosystem/abstract/breeds/breeds.h \
    ecosystem/abstract/eats/eats.h \
    ecosystem/abstract/breeds/breeds.h \
    ecosystem/abstract/eats/eats.h \
    ecosystem/abstract/moves/moves.h \
    ecosystem/abstract/dies/dies.h \

LIBS += -lncurses

LIBS += -L"/home/allen/SFML/lib"

CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += "/home/allen/SFML/include"
DEPENDPATH += "/home/allen/SFML/include"
