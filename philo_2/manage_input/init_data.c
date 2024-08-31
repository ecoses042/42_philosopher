#include "../philosopher.h"

//0 for print
//1 for m_die
//2 for m_eat
//3 for m_all_eat
//4 for all fork in phils
bool	data_mutex_destroy(t_data	*info, int mode, char *msg)
{
	int	i;

	i = -1;
	if (mode >= 0)
		pthread_mutex_destroy(&info->print);
	if (mode >= 1)
		pthread_mutex_destroy(&info->m_die);
	if (mode >= 3)
		pthread_mutex_destroy(&info->m_all_eat);
	if (mode == 4)
	{
		while (++i < info->n_phil)
			pthread_mutex_destroy(&info->phils[i].l_fork);
		free(info->phils);
	}
	if (msg)
		return	(print_error(msg));
	return (false);
}

bool	ft_init_info_mutex(t_data *info)
{
	if (pthread_mutex_init(&info->print, NULL))
		return (print_error(MUTEXALLOC_FAIL));
	if (pthread_mutex_init(&info->m_die, NULL))
		return (data_mutex_destroy(info, 0, MUTEXALLOC_FAIL));
	if (pthread_mutex_init(&info->m_all_eat, NULL))
		return (data_mutex_destroy(info, 2, MUTEXALLOC_FAIL));
	return (true);
}

//set basic information about sleep time, death time etc..
bool	init_info(int ac, char **av, t_data *info)
{
	info->n_phil = ft_atoi(av[1]);
	info->t_die = ft_atoi(av[2]);
	info->t_eat = ft_atoi(av[3]);
	info->t_sleep = ft_atoi(av[4]);
	info->all_eat_count = 0;
	info->death = 0;
	if (ac == 6)
		info->t_rep = ft_atoi(av[5]);
	else
		info->t_rep = -42;
	if (!ft_init_info_mutex(info))
		return (false);
	info->phils = malloc(sizeof(t_phil) * info->n_phil);
	if (!info->phils)
		return data_mutex_destroy(info, 3, ALLOC_ERR);
	return (true);	
}