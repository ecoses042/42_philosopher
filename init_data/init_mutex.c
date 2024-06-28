#include "../philo.h"

bool init_mutex(t_data *info)
{
    int i;

    i = -1;
    info->phil = malloc(sizeof(t_phil) * info->p_num);
    if (!info->phil)
        return (false);   
    info->forks = malloc(sizeof(pthread_mutex_t) * info->p_num);
    if (!info->forks)
        return (false);
    while (++i < info->p_num)
    {
        info->phil[i].data = info;
        if (pthread_mutex_init(&info->forks[i], NULL))
            return (false);
    }
    pthread_mutex_init(&info->print, NULL);
    return (true);
}