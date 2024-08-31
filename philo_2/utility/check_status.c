#include "../philosopher.h"

//return false if alive
//return true if dead or rep encounter
bool	is_dead(t_phil *param)
{
    long current_time;
	
	current_time = get_time();  // 현재 시간을 가져옴
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
	if (param->info->all_eat_count / param->info->n_phil == param->info->t_rep)
		return (!print_error(MAX_REP));
    return (false);
}

//0 for thinking
//1 for taken fork
//2 for eating
// 3 for sleeping
// 4 for die
void	print_status(t_phil	*param, int mode)
{
	long long	time;


	pthread_mutex_lock(&(param->info->print));
	time = get_time();
	printf("%lld %d ", time - param->start_time, param->n);
	if (mode == 0)
		printf("is thinking\n");
	else if (mode == 1)
		printf("has taken a fork\n");
	else if (mode == 2)
		printf("is eating\n");
	else if (mode == 3)
		printf("is sleeping\n");
	else if (mode == 4)
	{
		printf("died\n");
		pthread_mutex_destroy(&param->info->print);
		return ;
	}
	pthread_mutex_unlock(&(param->info->print));
}