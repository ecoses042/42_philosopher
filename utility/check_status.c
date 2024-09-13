#include "../philosopher.h"

//return false if alive
//return true if dead or rep encounter
bool	is_dead(t_phil *param)
{
	long	current_time;

	current_time = get_time();
	if (param->last_eat == 0)
	{
		if (current_time - param->start_time >= param->info->t_die)
			return (process_dead(param));
	}	
	else
	{
		if (current_time - param->last_eat >= param->info->t_die)
			return (process_dead(param));
	}
	if (is_rep_condition(param->info))
		return (true);
	return (false);
}

//0 for thinking
//1 for taken fork
//2 for eating
// 3 for sleeping
// 4 for die
void	print_status(t_phil	*param, char *msg, bool mode)
{
	long long	time;

	pthread_mutex_lock(&(param->info->print));
	time = get_time();
	printf("%lld %d %s\n", time - param->start_time, param->n, msg);
	if (mode == 1)
		return ;
	pthread_mutex_unlock(&(param->info->print));
}
