#include "../philosopher.h"

//assign index
//set l_fork value and init mutex

bool init_philo(t_data *info)
{
	int	i;

	i = -1;
	while (++i < info->n_phil)
	{
		info->phils[i].n = i + 1;
		info->phils[i].last_eat = 0;
		info->phils[i].r_fork = NULL;
		info->phils[i].info = info;
		if (pthread_mutex_init(&info->phils[i].l_fork, NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&info->phils[i].l_fork);
			return(data_mutex_destroy(info, 3, MUTEXALLOC_FAIL));
		}
		if (i == info->n_phil - 1)
			info->phils[i].r_fork = &(info->phils[0].l_fork);
		else
			info->phils[i].r_fork = &(info->phils[i + 1].l_fork);
	}
	return (true);
}