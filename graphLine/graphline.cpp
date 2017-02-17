#include "graphline.h"

graphLine::graphLine(unsigned int num, unsigned int width, unsigned int length)
{
    // Get video modes
    videoModes = sf::VideoMode::getFullscreenModes();

    // Set title
    title = "Predator/Prey Time Graph";

    // Default render window dimension
    if(!width && !length)
        rWindow.create(videoModes[35], title);

    // Custom render window dimension
    else
        rWindow.create(sf::VideoMode(width, length), title);

    // Window ETC
    rWindow.setKeyRepeatEnabled(true);
    rWindow.setFramerateLimit(60);
    rWindow.setVerticalSyncEnabled(true);

    // Set view
    view.setSize(rWindow.getSize().x, rWindow.getSize().y);

    // Set background
    background.setSize(view.getSize());
    background.setFillColor(sf::Color::Black);

    // Graph width multiplier
    xMultiplier = 5;

    // Number of graphs to display
    numGraphs = num;

    // Create vertex array
    graphs = new sf::VertexArray[numGraphs];

    // Time
    time = new unsigned int[numGraphs];

    for(int i = 0; i < numGraphs; i++)
    {
        // Clear time
        time[i] = 0;

        // Set vertex array type
        graphs[i].setPrimitiveType(sf::LinesStrip);
    }
}

graphLine::~graphLine()
{
    delete time;
    numGraphs = xMultiplier = NULL;
}

void graphLine::addPoint(int index, double pos, sf::Color color)
{
    // Overflow: shift graph to the left
    if(graphs[index].getVertexCount() >= view.getSize().x/xMultiplier)
    {
        for(int i = 0; i < graphs[index].getVertexCount() - 1; i++)
        {
            graphs[index][i] = graphs[index][i+1];
            sf::Vector2f pos = (graphs[index][i]).position;
            graphs[index][i].position = sf::Vector2f(pos.x - xMultiplier, pos.y);
        }
        time[index]--;
        graphs[index].resize(graphs[index].getVertexCount() - 1);
    }

    // Append point to graph
    graphs[index].append(sf::Vertex(sf::Vector2f(xMultiplier * time[index]++, view.getSize().y - (pos/2)), color));
}

void graphLine::render()
{
    // Clear the window
    rWindow.clear();

    // Draw graph
    rWindow.draw(background);
    for(int i = 0; i < numGraphs; i++)
        rWindow.draw(graphs[i]);

    // Display the window
    rWindow.display();
}

void graphLine::clear()
{
    for(int i = 0; i < numGraphs; i++)
    {
        graphs[i].clear();
        time[i] = 0;
    }
}
