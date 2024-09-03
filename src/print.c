#include "puzzle_solver.h"

void print_list(int *list, int size)
{
    int i = 0;
    while (i < size)
    {
        printf("%d ", list[i]);
        i++;
    }
    printf("\n");
}

void print_puzzle(Puzzle* puzzle)
{
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (puzzle->matrix[row][col] == 13)
                printf(BLACK_COLOR"%2d "RESET_COLOR, puzzle->matrix[row][col]);
            else if (puzzle->matrix[row][col] == 1)
                printf(RED_COLOR"%2d "RESET_COLOR, puzzle->matrix[row][col]);
            else if (puzzle->matrix[row][col] == 2)
                printf(GREEN_COLOR"%2d "RESET_COLOR, puzzle->matrix[row][col]);
            else if (puzzle->matrix[row][col] == 3)
                printf(YELLOW_COLOR"%2d "RESET_COLOR, puzzle->matrix[row][col]);
            else if (puzzle->matrix[row][col] == 4)
                printf(BLUE_COLOR"%2d "RESET_COLOR, puzzle->matrix[row][col]);
            else if (puzzle->matrix[row][col] == 5)
                printf(MAGENTA_COLOR"%2d "RESET_COLOR, puzzle->matrix[row][col]);
            else if (puzzle->matrix[row][col] == 6)
                printf(CYAN_COLOR"%2d "RESET_COLOR, puzzle->matrix[row][col]);
            else if (puzzle->matrix[row][col] == 7)
                printf(BRIGHT_MAGENTA_COLOR"%2d "RESET_COLOR, puzzle->matrix[row][col]);
            else if (puzzle->matrix[row][col] == 8)
                printf(BRIGHT_BLACK_COLOR"%2d "RESET_COLOR, puzzle->matrix[row][col]);
            else if (puzzle->matrix[row][col] == 9)
                printf(BRIGHT_RED_COLOR"%2d "RESET_COLOR, puzzle->matrix[row][col]);
            else if (puzzle->matrix[row][col] == 10)
                printf(BRIGHT_GREEN_COLOR"%2d "RESET_COLOR, puzzle->matrix[row][col]);
            else if (puzzle->matrix[row][col] == 11)
                printf(BRIGHT_YELLOW_COLOR"%2d "RESET_COLOR, puzzle->matrix[row][col]);
            else if (puzzle->matrix[row][col] == 12)
                printf(BRIGHT_BLUE_COLOR"%2d "RESET_COLOR, puzzle->matrix[row][col]);
            else
                printf("%2d ", puzzle->matrix[row][col]);
        }
        printf("\n");
    }
}
void print_figure_placed(int id, int start_col, int start_row, Puzzle *puzzle)
{
    printf("Figure %d placed | Col: %d | Row: %d | Counted: %d\n", id, start_col, start_row, counted);
    print_puzzle(puzzle);
    printf("\n");
}

int err_msg(void)
{
    printf("%s\n", ERR_MSG);
    printf("%s\n", DESC_MSG);
    return 1;
}