#include "../philosopher.h"

bool	is_death_condition(t_data	*info)
{
	return (info->death != 0);
}

bool	is_rep_condition(t_data	*info)
{
	if (info->t_rep != INIT_LOOP_VALUE)
		return (info->all_eat_count / info->n_phil >= info->t_rep);
	return (false);
}

void	*monitor(void	*param)
{
	t_data	*info;
	t_phil	*philo;

	info = (t_data *)param;
	philo = info->phils;
	while (1)
	{
		usleep(1000);
		if (is_death_condition(info))
		{
			print_status(&philo[info->death], DEATH, 1);
			break ;
		}
		if (is_rep_condition(info))
		{
			print_status(&philo[info->death], MAX_REP, 1);
			break ;
		}
	}
	return (NULL);
}

bool	is_monitor_create_fail(pthread_t *check, t_data *info)
{
	return (pthread_create(check, NULL, monitor, info));
}
