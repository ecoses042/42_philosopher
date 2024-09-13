#include "../philosopher.h"

void	*init_thread(void	*param)
{
	bool	flag;
	t_phil	*philo;
	t_data	*info;

	philo = (t_phil *)param;
	info = philo->info;
	flag = true;
	philo->start_time = get_time();
	if (philo->n % 2)
		init_time(philo);
	while (flag)
		flag = manage_action(philo);
	return (NULL);
}

bool	is_thread_init_failed(t_data *info, int index)
{
	return (pthread_create(&(info->phils[index].thread), NULL, \
		init_thread, &(info->phils[index])));
}

bool	manage_thread(t_data	*info)
{
	int			i;
	pthread_t	check;

	i = -1;
	while (++i < info->n_phil)
	{
		if (is_thread_init_failed(info, i))
			return (data_mutex_destroy(info, 4, THREAD_FAIL));
	}
	if (is_monitor_create_fail(&check, info))
		return (data_mutex_destroy(info, 4, THREAD_FAIL));
	pthread_join(check, NULL);
	pthread_mutex_destroy(&info->print);
	return (false);
}
