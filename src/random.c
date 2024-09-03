#include "puzzle_solver.h"

int random_list_func(int *list, int size, int min, int max)
{
    int i = 0;
    int tmp = 0;
    while (i < size)
    {
        list[i] = get_random_number(min, max);
        tmp = test_unique(list, i);
        if (tmp == 1)
            i++;
    }
}

int test_unique(int *list, int index)
{
    int i = 0;
    int j = 0;
    if (index == 0)
        return 1;
    while (i < index)
    {
        j = i + 1;
        while (j <= index)
        {
            if (list[i] == list[j])
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

int get_random_number(int min, int max)
{
    return rand() % (max - min + 1) + min;
}