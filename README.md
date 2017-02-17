# Predator Prey
2D predator prey simulation using ncurses for displaying the grid and SFML for displaying the population time graph.

# Model
The ecosystem is a 40x40 grid in which each cell may be inhabited by a single creature. The grid is initialized with 5 % of it being composed of predators and 25 % of it being composed of prey at random locations. While the simulation is running, the program loops through the entire grid to call each creature's event function.

In this model, the creatures contain stats that *mostly* dictate their behaviors as opposed to the master branch model having RNG and behaviorial rates decide their actions.

The predator's behaviors in its event function follows these rules and will perform one action out of the following:
- If adjacent to a prey, it will eat the prey.
   - If the predator has eaten 30 times since giving birth, it will also give birth on the prey's position.
- If health is reduced to 0, it will die.
- If adjacent to empty space, it will move towards the empty space.

The prey's behaviors in its event function follows these rules and will perform one action out of the following:
- If health is reduced to 0, it will die.
- If adjacent to empty space
  - If the predator has moved 5 times since giving birth, it will give birth on the empty space.
  - Else there is a 90 % chance it will move towards the empty space.
- Else, it will idle.

Note that if a creature is adjacent to multiple cells that satisfy its behavioral requirements, it will randomly select one cell to act on.

This model is less predictable and cyclical compared to the master branch, and movement in the ecosystem is much slower. However, both species are seemingly less susceptible to extinction.

# Dependencies
- [SFML 2.3.2] (https://www.sfml-dev.org/)
- [ncurses 6.0] (https://www.gnu.org/software/ncurses/)

# Screenshots
![grid](screenshots/grid.png)
![graph](screenshots/graph.png)

# License
This project is released under MIT License. Please review the [License file](LICENSE) for more details.
