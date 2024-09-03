#include "puzzle_solver.h"

bool can_place_figure(Puzzle* puzzle, int figure[F][F], int start_row, int start_col)
{
    for (int row = 0; row < F; row++) {
        for (int col = 0; col < F; col++) {
            if (figure[row][col] == 1) {
                int puzzle_row = start_row + row;
                int puzzle_col = start_col + col;
                if (puzzle_row >= N || puzzle_col >= N || puzzle->matrix[puzzle_row][puzzle_col] != 20) {
                    return false;
                }
            }
        }
    }
    return true;
}

void place_figure(Puzzle* puzzle, int figure[F][F], int start_row, int start_col, int id)
{
    for (int row = 0; row < F; row++) {
        for (int col = 0; col < F; col++) {
            if (figure[row][col] == 1) {
                puzzle->matrix[start_row + row][start_col + col] = id;  
            }
        }
    }
}

void reset_puzzle(Puzzle *puzzle, const int initial_matrix[N][N])
{
    memcpy(puzzle->matrix, initial_matrix, sizeof(int) * N * N);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - '0');
	return (result * sign);
}

int handle_debug(int *debug, int *utime, char *s, char *c)
{
    double a;
    double b;

    a = ft_atoi(s); 
    b = ft_atoi(c);
    if (a > 2 || a < 0)
        return 0;
    if (b > INT_MAX || b < 0)
        return 0;
    *debug = a;
    *utime = b;
}