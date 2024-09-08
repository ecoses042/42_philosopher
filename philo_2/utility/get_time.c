#include "../philosopher.h"

long long	get_time(void)
{
	long long		sec;
	long long		usec;
	struct timeval	time;

	gettimeofday(&time, NULL);
	sec = (long long)(time.tv_sec) *1000;
	usec = (long long)(time.tv_usec) / 1000;
	return (sec + usec);
}

void	safe_usleep(long long time_in_ms, t_phil *philo)
{
	long long	start_time;
	long long	current_time;

	start_time = get_time();
	while (1)
	{
		usleep(1000);
		current_time = get_time();
		if (is_dead(philo))
			break;
		if (current_time - start_time >= time_in_ms)
			break ;
	}
}

void	init_time(t_phil	*philo)
{
	t_data	*info;

	info = philo->info;
	philo->start_time = get_time();
	if (info->t_die >= info->t_eat)
		safe_usleep(info->t_eat, philo);
	else
		safe_usleep(info->t_die, philo);
}
