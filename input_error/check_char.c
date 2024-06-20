#include "../philo.h"

bool is_valid_char_input(const char **av)
{
    int i;
    int j;

    i = 0;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] < 48 || av[i][j] > 57)
                return false;
            j++;
        }
        i++;
    }
    return true;
}