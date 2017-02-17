#include "ecosystem.h"

ecosystem::ecosystem(const int i, const int j)
{
    // Start curses
    initscr();                      // Initialize screen
    curs_set(0);                    // No blinking cursor
    if(hasColor = has_colors())     // Initialize colors if possible
    {
        start_color();
        init_pair(1, COLOR_BLACK, COLOR_BLACK);
        init_pair(2, COLOR_CYAN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    }

    // Set row and col
    gridMax.row = i;
    gridMax.col = j;

    // Create and load grid
    createGrid();
    loadGrid();

    // Create graph line
    graph = new graphLine(2, 1000, 765);

    // Set duration time to default value
    durationTime = sf::seconds(0);
}

ecosystem::~ecosystem()
{
    // Clear and delete grid
    deleteGrid();
    delete graph;

    hasColor = NULL;
}

void ecosystem::run()
{
    // Ecosystem inhabited by creatures
    while(count('0') && count('X'))
    {
        // Call events
        event();

        // Print grid to terminal
        printGrid();

        // Render graph
        graph->render();
    }

    // Extinction of all creatures
    while(true)
    {
        // Total duration of existence
        if(durationTime.asSeconds() == 0)
            durationTime = durationClock.getElapsedTime();

        // Game over
        mvprintw(10, 17, "%s", "GAME OVER");
        mvprintw(11, 18, "%f", durationTime.asSeconds());
        refresh();

        // Render graph
        graph->render();
    }
}

void ecosystem::resize(int i, int j)
{
    // Delete grid
    deleteGrid();

    // Assign grid row and columns
    gridMax.row = i;
    gridMax.col = i;

    // Create and load grid
    createGrid();
    loadGrid();
}

void ecosystem::createGrid()
{
    // Create grid according to row and size values
    grid = new creature**[gridMax.row];
    for(int i = 0; i < gridMax.row; i++)
        grid[i] = new creature*[gridMax.col];

    // Clear grid
    for(int i = 0; i < gridMax.row; i++)
        for(int j = 0; j < gridMax.col; j++)
            grid[i][j] = nullptr;
}

void ecosystem::loadGrid()
{
    // Spawn creatures
    spawn('0', gridMax.row * gridMax.col * 0.25);
    spawn('X', gridMax.row * gridMax.col * 0.1);
}

void ecosystem::deleteGrid()
{
    // Clear and delete grid
    for(int i = 0; i < gridMax.row; i++)
        for(int j = 0; j < gridMax.col; j++)
        {
            if(isOccupied(i,j))
                delete grid[i][j];
            grid[i][j] = nullptr;
        }

    for(int i = 0; i < gridMax.row; ++i)
    {
        if(grid[i])
            delete grid[i];
        grid[i] = nullptr;
    }
    delete grid;
    grid = nullptr;
}

void ecosystem::spawn(char face, int population)
{
    for(int tries = 0; tries < population;)
    {
        int i = (dist(rd))%(gridMax.row);
        int j = (dist(rd))%(gridMax.col);
        if(!isOccupied(i,j))
        {
            switch(face)
            {
                case '0':   grid[i][j] = new prey(grid, gridMax, i, j);
                            break;
                case 'X':   grid[i][j] = new predator(grid, gridMax, i, j);
                            break;
                default:    grid[i][j] = nullptr;
                            break;
            }
            tries++;
        }
    }
}

void ecosystem::event()
{
    // Loop through entire grid
    for(int i = 0; i < gridMax.row; i++)
        for(int j = 0; j < gridMax.col; j++)

            // Call creature's events
            if(isOccupied(i,j))
                grid[i][j]->event();

    // Add points to graph
    graph->addPoint(0, count('0'), sf::Color::Cyan);
    graph->addPoint(1, count('X'), sf::Color::Red);
}

void ecosystem::printGrid()
{
    // Loop through entire grid
    for(int i = 0; i < gridMax.row; i++)
        for(int j = 0; j < gridMax.col; j++)

            // Creature found
            if(isOccupied(i,j))
            {
                // Print by the color
                if(hasColor)
                {
                    attron(COLOR_PAIR(grid[i][j]->color()));
                    mvprintw(i, j*2, "%c", '0');
                    attroff(COLOR_PAIR(grid[i][j]->color()));
                }

                // Print by the face
                else
                {
                    mvprintw(i, j*2, "%c", grid[i][j]->face());
                }
            }

            // Empty space
            else
            {
                mvprintw(i, j*2, "%c", ' ');
            }

    refresh();
}

int ecosystem::count()
{
    int count = 0;
    for(int i = 0; i < gridMax.row; i++)
        for(int j = 0; j < gridMax.col; j++)
            if(isOccupied(i,j))
                count++;
    return count;
}

int ecosystem::count(char face)
{
    int count = 0;
    for(int i = 0; i < gridMax.row; i++)
        for(int j = 0; j < gridMax.col; j++)
            if(isOccupied(i,j) && grid[i][j]->face() == face)
                count++;
    return count;
}
