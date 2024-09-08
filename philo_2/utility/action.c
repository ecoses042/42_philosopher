#include "../philosopher.h"

//eating counter needs to be added
bool	eat(t_phil *philo)
{
	t_data	*info;

	info = philo->info;
	if (is_dead(philo))
		return (true);
	if (info->n_phil == 1)
		ft_one_phil(philo);
	else
	{
		pick_fork(philo);
		print_status(philo, EAT, 0);
		pthread_mutex_lock(&info->m_all_eat);
		info->all_eat_count++;
		pthread_mutex_unlock(&info->m_all_eat);
		safe_usleep(info->t_eat, philo);
		if (is_dead(philo))
			return (unlock_eat(philo, true));
		philo->last_eat = get_time();
		unlock_eat(philo, false);
	}
	return (is_dead(philo));
}

bool	sleeping(t_phil	*philo)
{
	print_status(philo, SLEEP, 0);
	safe_usleep(philo->info->t_sleep, philo);
	return (is_dead(philo));
}

bool	process_dead(t_phil	*phil)
{
	pthread_mutex_lock(&phil->info->m_die); 
	phil->info->death = phil->n;
	pthread_mutex_unlock(&phil->info->m_die);
	return (true);
}

bool	manage_action(t_phil	*philo)
{
	if (eat(philo))
		return (false);
	if (sleeping(philo))
		return (false);
	print_status(philo, THINK, 0);
	return (true);
}
