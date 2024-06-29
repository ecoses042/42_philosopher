#include "../philo.h"

void ft_free(t_data *info)
{
    if (info->phil)
        free(info->phil);
    if (info->forks)
        free(info->forks);
}

void ft_exit(t_data *info)
{
    int i;

    i = -1;
    while (++i < info->p_num)
    {
        pthread_mutex_destroy(&info->forks[i]);
    }
    pthread_mutex_destroy(&info->print);
    ft_free(info);
}