#include "../philosopher.h"

bool	unlock_eat(t_phil	*philo, bool flag)
{
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (flag);
}

void	pick_fork(t_phil	*philo)
{
	pthread_mutex_lock(&philo->l_fork);
	print_status(philo, FORK, 0);
	pthread_mutex_lock(philo->r_fork);
	print_status(philo, FORK, 0);
}