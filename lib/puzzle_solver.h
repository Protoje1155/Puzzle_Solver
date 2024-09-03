#ifndef PUZZLE_SOLVER_H
#define PUZZLE_SOLVER_H
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define N 17 
#define F 9
#define SEC 1000000
#define MILISEC 1000
#define ERR_MSG RED_COLOR"\nERROR: Incorrect Input!" RESET_COLOR
#define DESC_MSG GREEN_COLOR"TRY: ./solver <debug_value> <micro_sec>\n"RESET_COLOR YELLOW_COLOR"DESCRIPTION:\n"RESET_COLOR"debug 0: print when 12 placed\ndebug 1: print every step\ndebug 2: print only solution\nmicro_seconds: range(0, 2^31-1)\n"
#define RESET_COLOR "\x1b[0m"
#define BLACK_COLOR "\x1b[30m"
#define RED_COLOR "\x1b[31m"
#define GREEN_COLOR "\x1b[32m"
#define YELLOW_COLOR "\x1b[33m"
#define BLUE_COLOR "\x1b[34m"
#define MAGENTA_COLOR "\x1b[35m"
#define CYAN_COLOR "\x1b[36m"
#define WHITE_COLOR "\x1b[37m"
#define BRIGHT_BLACK_COLOR "\x1b[90m"
#define BRIGHT_RED_COLOR "\x1b[91m"
#define BRIGHT_GREEN_COLOR "\x1b[92m"
#define BRIGHT_YELLOW_COLOR "\x1b[93m"
#define BRIGHT_BLUE_COLOR "\x1b[94m"
#define BRIGHT_MAGENTA_COLOR "\x1b[95m"
#define BRIGHT_CYAN_COLOR "\x1b[96m"
#define BRIGHT_WHITE_COLOR "\x1b[97m"

typedef struct puzzle{
    int matrix[N][N];
    int size;
} Puzzle;

typedef struct figure{
    int matrix_flip0[F][F];
    int matrix_flip1[F][F];
    int matrix_flip2[F][F];
    int matrix_flip3[F][F];
    int id;
} Figure;
extern Figure figure0;
extern Figure figure1;
extern Figure figure2;
extern Figure figure3;
extern Figure figure4;
extern Figure figure5;
extern Figure figure6;
extern Figure figure7;
extern Figure figure8;
extern Figure figure9;
extern Figure figure10;
extern Figure figure11;
extern Figure figure12;
extern int counted;
extern const int matrix[N][N];

void print_list(int *list, int size);
int random_list_func(int *list, int size, int min, int max);
int test_unique(int *list, int index);
int get_random_number(int min, int max);
int test_puzzle(Puzzle *puzzle, Figure *figure1, int id, int debug);
int algorithm_solver(Puzzle *puzzle, Figure *figure, int debug, int utime);
int figure_chooser(Puzzle *puzzle, int debug, int utime, int *list);
int test_and_place(int start_col, int start_row, Puzzle *puzzle, Figure *figure, int id, int debug, int *flag, int rand);
void print_puzzle(Puzzle* puzzle);
bool can_place_figure(Puzzle* puzzle, int figure[F][F], int start_row, int start_col);
void place_figure(Puzzle* puzzle, int figure[F][F], int start_row, int start_col, int id);
void reset_puzzle(Puzzle *puzzle, const int initial_matrix[N][N]);
void print_figure_placed(int id, int start_col, int start_row, Puzzle *puzzle);
int	ft_atoi(const char *nptr);
int handle_debug(int *debug, int *utime, char *s, char *c);
int main_solver(Puzzle *puzzle, int debug, int utime);
int ext_test_and_place(Puzzle *puzzle, int matrixflipx[F][F], int start_col, int start_row, int id, int *flag, int debug);
int err_msg(void);
#endif