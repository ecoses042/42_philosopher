#include "../philosopher.h"

bool	ft_one_phil(t_phil	*philo)
{
	t_data	*info;

	info = philo->info;
	safe_usleep(info->t_die, philo);
	return (is_dead(philo));
}