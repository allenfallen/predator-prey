# Predator Prey
2D predator prey simulation using ncurses for displaying the grid and SFML for displaying the population time graph.2

# Model
The ecosystem is a 40x40 grid in which each cell may be inhabited by a single creature. The grid is initialized with 5 % of it being composed of predators and 12 % of it being composed of prey at random locations. While the simulation is running, the program loops through the entire grid to call each creature's event function.

The predator's behaviors in its event function follows these rules and will perform one action out of the following:
- If adjacent to a prey, it will eat the prey. 
   - There is also a 45 % chance to give birth on the prey's position.
- If the predator has not eaten or given birth, there is a 50 % chance to die.
- If adjacent to empty space, it will move towards the empty space.

The prey's behaviors in its event function follows these rules and will perform one action out of the following:
- If adjacent to a predator, there is a 45 % chance to die.
- If adjacent to empty space
   - There is a 66 % chance to give birth on the empty space. 
   - If not giving birth, it will move towards the empty space.

Note that if a creature is adjacent to multiple cells that satisfy its behavioral requirements, it will randomly select one cell to act on.

This model results in a predictable and cyclical change in population sizes similar to the Lotka–Volterra model. However, there is a moderate chance that random perturbations may lead to the extinction of a species.


# Dependencies
- [SFML 2.3.2] (https://www.sfml-dev.org/)
- [ncurses 6.0] (https://www.gnu.org/software/ncurses/)

# Screenshots
![grid](screenshots/grid.png)
![graph](screenshots/graph.png)

# License
This project is released under MIT License. Please review the [License file](LICENSE) for more details.
