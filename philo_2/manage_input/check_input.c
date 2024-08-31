#include "../philosopher.h"

bool is_valid_char_input(int ac, char **av)
{
    int i;
    int j;

    i = 1;
	if (ac < 5 || ac > 6)
		return (print_error(INVALID_INPUT));
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] < 48 || av[i][j] > 57)
                return print_error(INVALID_INPUT);
            j++;
        }
        i++;
    }
    return (true);
}