#include "../philosopher.h"

void	init_philo_basic(t_data	*info, int index)
{
	info->phils[index].n = index + 1;
	info->phils[index].last_eat = 0;	
	info->phils[index].info = info;
}

bool	init_philo_fork(t_data *info, int index)
{
	info->phils[index].r_fork = NULL;
	if (pthread_mutex_init(&info->phils[index].l_fork, NULL))
	{
		while (--index >= 0)
			pthread_mutex_destroy(&info->phils[index].l_fork);
		return (data_mutex_destroy(info, 3, MUTEXALLOC_FAIL));
	}
	if (index == info->n_phil - 1)
		info->phils[index].r_fork = &(info->phils[0].l_fork);
	else
		info->phils[index].r_fork = &(info->phils[index + 1].l_fork);
	return (true);
}

bool	init_philo(t_data *info)
{
	int	i;

	i = -1;
	while (++i < info->n_phil)
	{
		init_philo_basic(info, i);
		if (!init_philo_fork(info, i))
			return (false);
	}
	return (true);
}
