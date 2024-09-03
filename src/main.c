#include "puzzle_solver.h"

/*
debug 0: print 12 counted
debug 1: print every step
debug 2: print puzzle solved
*/

int main(int argc, char **argv)
{
    Puzzle puzzle;
    int utime = 0;
    int debug = 0;

    if (argc != 3 || (handle_debug(&debug, &utime, argv[1], argv[2]) == 0))
        return (err_msg());
    srand(time(NULL));
    main_solver(&puzzle, debug, utime);
    print_puzzle(&puzzle);
    return 0;
}