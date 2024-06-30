#include "../philo.h"

//this function will return current time in milisecond.
int	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (print_error("gettimeofday() FAILURE\n", NULL));
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}