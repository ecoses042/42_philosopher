#include "../philosopher.h"

//each action will check for death at the end of the action
//if dead, return true
//if init_thread detacts false return, break while and call process_dead
bool	ft_one_phil(t_phil *philo)
{
	t_data	*info;

	info = philo->info;

	usleep(info->t_die * 1000);
	return (is_dead(philo));
}

bool	unlock_eat(t_phil	*philo, bool flag)
{
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (flag);
}

void	ft_usleep(long long	sleep_time, long long start_time, t_phil *philo)
{
	long long	current;

	while (1)
	{
		current = get_time() - start_time;
		if (current >= philo->info->t_die)
			
		if (current >= sleep_time)
			break;
		usleep(50);
	}
}
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
		pthread_mutex_lock(&philo->l_fork);
		print_status(philo, 1);
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, 1);
		print_status(philo, 2);
		info->all_eat_count++;
		usleep(info->t_eat * 1000);
		if (is_dead(philo))
			return (unlock_eat(philo, true));
		philo->last_eat = get_time();
		unlock_eat(philo, false);
	}
	return (is_dead(philo));
}
bool	sleeping(t_phil	*philo)
{
	print_status(philo, 3);
	usleep(philo->info->t_sleep * 1000);
	return (is_dead(philo));
}

bool	thinking(t_phil	*philo)
{
	print_status(philo, 0);
	return (is_dead(philo));
}
bool	process_dead(t_phil	*phil)
{
	pthread_mutex_lock(&phil->info->m_die);
	phil->info->death = phil->n;
	pthread_mutex_unlock(&phil->info->m_die);
	return (true);
}


void	init_time(t_data	*info)
{
	if (info->t_die >= info->t_eat)
		usleep((info->t_eat - 1) * 1000);
	else
		usleep((info->t_die - 1)  * 1000);
}
//if index is even eat first
//if index is odd, eat second
//usleep(1000) = get_time return 1
//info->eat_count / info->n_phil == repetition count
//if rep count == info->t_rep, return true
void	*init_thread(void	*param)
{
	t_phil	*philo;
	t_data	*info;

	philo = (t_phil	*)param;
	info = philo->info;
	philo->start_time = get_time();
	if (philo->n % 2)
		init_time(info);
	while (1)
	{
		if (eat(philo))
			break;
		if (sleeping(philo))
			break;
		if (thinking(philo))
			break;
	}
	return NULL;
}

void	*monitor(void	*param)
{
	t_data	*info;
	t_phil	*philo;

	info = (t_data *)param;
	philo = info->phils;
	while (1)
	{
		usleep(info->t_die * 1000);
		if (info->death || info->all_eat_count / info->n_phil == info->t_rep)
			break;
	}
	process_dead(&philo[info->death - 1]);
	print_status(&philo[info->death - 1], 4);
	return NULL;
}
//run though t_info and init thread
bool	manage_thread(t_data	*info)
{
	int	i;
	pthread_t	check;

	i = -1;
	while (++i < info->n_phil)
	{
		if (pthread_create(&(info->phils->thread), NULL, init_thread, &(info->phils[i])))
			return (data_mutex_destroy(info, 4, THREAD_FAIL));
	}
	if (pthread_create(&check, NULL, monitor, info))
		return (data_mutex_destroy(info, 4, THREAD_FAIL));
	pthread_join(check, NULL);
	return (false);
}