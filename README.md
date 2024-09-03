# Random Puzzle Solver
## Overview
- This project is a C-based puzzle solver that attempts to place 13 distinct forms onto a grid. The solver uses random placement to try and fill the grid with all the forms. The program ends successfully when all 13 forms are placed. Additionally, the program supports different debugging levels, allowing you to control the amount of information printed during the solving process.
## Usage
- Run the solver using the following command:
```
./solver <debug_value> <micro_sec>
```
- <debug_value>: Set the debug level (0, 1, or 2).
- <micro_sec>: Set the delay between each placement step (0 to 2^31-1 microseconds).
### Debugging Levels
#### Debug Level 0
- Only prints a message when 12 forms have been placed.
#### Debug Level 1
- Prints detailed information at every step of the solving process.
#### Debug Level 2
- Only prints the final solution when all 13 forms are placed.
