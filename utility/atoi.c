#include "../philo.h"

static	int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || \
			c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

long	ft_atoi(const char *str)
{
	long	nbr;
	long	sign;
	size_t	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while ((str[i]) && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i]) && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (sign * nbr);
}
