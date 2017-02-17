#ifndef GRAPHLINE_H
#define GRAPHLINE_H

// SFML library
#include "SFML/Graphics.hpp"
#include "SFML/Graphics.h"

// Vector
#include <vector>

class graphLine
{
    public:
        graphLine(unsigned int num = 2, unsigned int width = 0, unsigned int length = 0);
        ~graphLine();

        // Keys
        void event();

        // Print graph
        void render();

        // Add points to graph
        void addPoint(int index, double pos, sf::Color color);

        // Clear all data
        void clear();

        // Change number of indices
        void numIndex(unsigned int num);

        // Change dimension
        void resize(unsigned int width, unsigned int length);

    private:
        // Window
        sf::RenderWindow rWindow;
        sf::String title;
        std::vector<sf::VideoMode> videoModes;
        sf::View view;

        // Graph
        sf::VertexArray* graphs;
        unsigned int numGraphs;
        unsigned int *time;
        unsigned int xMultiplier;
        sf::RectangleShape background;
};

#endif // GRAPHLINE_H
