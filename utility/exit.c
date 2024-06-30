#include "../philo.h"

void ft_free(t_data *info)
{
    if (info->phils)
        free(info->phils);
    if (info->forks)
        free(info->forks);
    if (info->thds)
        free(info->thds);
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