#include "../philo.h"

bool init_mutex(t_data *info)
{
    int i;

    i = -1;
    info->phil = malloc(sizeof(t_phil) * info->p_num);
    if (!info->phil)
        return (print_error(MUTEXALLOC_FAIL, NULL));   
    info->forks = malloc(sizeof(pthread_mutex_t) * info->p_num);
    if (!info->forks)
        return (print_error(MUTEXALLOC_FAIL, info));
    while (++i < info->p_num)
    {
        info->phil[i].data = info;
        info->phil[i].id = i;
        if (pthread_mutex_init(&info->forks[i], NULL))
            return (print_error(MUTEXALLOC_FAIL, info));
    }
    pthread_mutex_init(&info->print, NULL);
    return (true);
}