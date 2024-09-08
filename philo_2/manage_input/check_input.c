#include "../philosopher.h"

bool	is_invalid_ac(int ac)
{
	return (ac < 5 || ac > 6);
}

bool	is_invalid_char(char check)
{
	return (check < 48 || check > 57);
}

bool	is_valid_char_input(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (is_invalid_ac(ac))
		return (print_error(INVALID_INPUT));
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (is_invalid_char(av[i][j]))
				return (print_error(INVALID_INPUT));
			j++;
		}
		i++;
	}
	return (true);
}
