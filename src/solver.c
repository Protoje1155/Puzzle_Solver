#include "puzzle_solver.h"

int test_puzzle(Puzzle *puzzle, Figure *figure1, int id, int debug)
{
    int flag = 0;
    int tmp = 0;
    int start_col = 0;
    int start_row = 0;
    int rand_list[4];
    
    while (start_col < N)
    {
        start_row = 0;
        if (flag == 1)
            break;
        while (start_row < N)
        {
            random_list_func(rand_list, 4, 0, 3);
            tmp = test_and_place(start_col, start_row, puzzle, figure1, id, debug, &flag, rand_list[0]);
            if (tmp == 0)
                break;
            else if (tmp == 2)
                return 2;
            else if (tmp == 1)
            {
                tmp = test_and_place(start_col, start_row, puzzle, figure1, id, debug, &flag, rand_list[1]);
                if (tmp == 0)
                    break;
                else if (tmp == 2)
                    return 2;
                else if (tmp == 1)
                {
                    tmp = test_and_place(start_col, start_row, puzzle, figure1, id, debug, &flag, rand_list[2]);
                    if (tmp == 0)
                        break;
                    else if (tmp == 2)
                        return 2;
                    else if (tmp == 1)
                    {
                        tmp = test_and_place(start_col, start_row, puzzle, figure1, id, debug, &flag, rand_list[3]);
                        if (tmp == 0)
                            break;
                        else if (tmp == 2)
                            return 2;
                        else if (tmp == 1)
                        {
                            start_row++;
                            if (start_row + 1 == N && start_col + 1 == N)
                            {
                                if (debug == 1)
                                    printf("couldnt place figure\n");
                                if (counted == 12 && debug == 0)
                                {
                                    printf("12 counted\n");
                                    print_puzzle(puzzle);
                                    printf("\n");
                                }
                                counted = 0;
                                return 1;
                            }
                        }
                    }
                }  
            }
        }
        start_col++;
    }
    return 0;
}

int algorithm_solver(Puzzle *puzzle, Figure *figure, int debug, int utime)
{
    int tmp = 0;
    tmp = test_puzzle(puzzle, figure, figure->id, debug);
    usleep(utime);
    if (tmp == 1)
        return 0;
    else if (tmp == 2)
    {
        printf("solution found\n");
        return 0;
    }
    return 1;
}

int figure_chooser(Puzzle *puzzle, int debug, int utime, int *list) {
    int i = 0;
    int tmp = 0;

    while (i < 12) {
        switch (list[i]) {
            case 1:
                tmp = algorithm_solver(puzzle, &figure1, debug, utime);
                break;
            case 2:
                tmp = algorithm_solver(puzzle, &figure2, debug, utime);
                break;
            case 3:
                tmp = algorithm_solver(puzzle, &figure3, debug, utime);
                break;
            case 4:
                tmp = algorithm_solver(puzzle, &figure4, debug, utime);
                break;
            case 5:
                tmp = algorithm_solver(puzzle, &figure5, debug, utime);
                break;
            case 6:
                tmp = algorithm_solver(puzzle, &figure6, debug, utime);
                break;
            case 7:
                tmp = algorithm_solver(puzzle, &figure7, debug, utime);
                break;
            case 8:
                tmp = algorithm_solver(puzzle, &figure8, debug, utime);
                break;
            case 9:
                tmp = algorithm_solver(puzzle, &figure9, debug, utime);
                break;
            case 10:
                tmp = algorithm_solver(puzzle, &figure10, debug, utime);
                break;
            case 11:
                tmp = algorithm_solver(puzzle, &figure11, debug, utime);
                break;
            case 12:
                tmp = algorithm_solver(puzzle, &figure12, debug, utime);
                break;
            default:
                break;
        }
        if (tmp == 0)
            return 1;
        i++;
    }
    return 0;
}

int ext_test_and_place(Puzzle *puzzle, int matrix_flipx[F][F], int start_col, int start_row, int id, int *flag, int debug)
{
    if (can_place_figure(puzzle, matrix_flipx, start_col, start_row))
    {
        place_figure(puzzle, matrix_flipx, start_col, start_row, id);
        if (debug == 1)
            print_figure_placed(id, start_col, start_row, puzzle);
        counted++;
        if (counted == 13)
            return 2;
        *flag = 1;
        return 0;
    }
    else
        return 1;
    return -1;

}

int test_and_place(int start_col, int start_row, Puzzle *puzzle, Figure *figure, int id, int debug, int *flag, int rand) {
    int tmp = 0;

    switch (rand) {
        case 0:
            tmp = ext_test_and_place(puzzle, figure->matrix_flip0, start_col, start_row, id, flag, debug);
            break;
        case 1:
            tmp = ext_test_and_place(puzzle, figure->matrix_flip1, start_col, start_row, id, flag, debug);
            break;
        case 2:
            tmp = ext_test_and_place(puzzle, figure->matrix_flip2, start_col, start_row, id, flag, debug);
            break;
        case 3:
            tmp = ext_test_and_place(puzzle, figure->matrix_flip3, start_col, start_row, id, flag, debug);
            break;
        default:
            return -1;
    }
    return tmp;
}


int main_solver(Puzzle *puzzle, int debug, int utime)
{
    int tmp = 0;
    int random_list[12];

    while (counted != 13)
    {
        reset_puzzle(puzzle, matrix);
        random_list_func(random_list, 12, 1, 12);
        while (1)
        {
            tmp = algorithm_solver(puzzle, &figure0, debug, utime);
            if (tmp == 0)
                break;
            if (figure_chooser(puzzle, debug, utime, random_list) == 1)
                break; 
        }
    }
}