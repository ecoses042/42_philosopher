#include "../philo.h"

//case of 1 philosopher as input
//since there are 1 fork, philosopher 1 will think until death
//therefore, return time of init_think, and time of death
bool case_one(const t_data *info)
{
    printf("0 1 is thinking\n");
    usleep(info->p_die_time*10);
    printf("%d 1 died\n",info->p_die_time);
    return (0);
}