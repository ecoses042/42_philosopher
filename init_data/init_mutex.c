#include "../philo.h"

bool init_alloc(t_data *info)
{
    info->phils = malloc(sizeof(t_phil) * info->p_num);
    if (!info->phils)
        return (print_error(MUTEXALLOC_FAIL, NULL));
    info->forks = malloc(sizeof(pthread_mutex_t) * info->p_num);
    if (!info->forks)
        return (print_error(MUTEXALLOC_FAIL, info));
    info->thds = malloc(sizeof(pthread_t) * info->p_num);
    if (!info->thds)
        return (print_error(THREAD_FAIL, info));
    return (true);
}

//set id
//set data connection
//reset status
//set time_until_die for temp
//reset start time
//set dead as false
//set left and right fork at the right place in info
bool init_phils(t_data *info)
{
    int i;

    i = -1;
    if (!info)
        return (print_error(INVALUD_INPUT2, NULL));
    while (++i < info->p_num)
    {
        info->phils[i].data = info;
        info->phils[i].id = i + 1;
        info->phils[i].eat_status = false;
        info->phils[i].think_status = false;
        info->phils[i].sleep_status = false;
        info->phils[i].time_until_die = info->p_die_time;
        info->phils[i].dead = false;
    }
    return (true);
}

bool init_mutex(t_data *info)
{
    int i;

    i = -1;
    while (++i < info->p_num)
    {
        if (pthread_mutex_init(&info->forks[i], NULL))
            return (print_error(MUTEXALLOC_FAIL, info));
    }
    i = -1;
    while (++i < info->p_num)
    {
        info->phils[i].left_fork = &info->forks[i];
        info->phils[i].right_fork = &info->forks[find_left_fork(i, info)];
    }
           
    if (pthread_mutex_init(&info->print, NULL))
        return (print_error(MUTEXALLOC_FAIL, info));
    return (true);
}
//sudo code
//allocate thds, phils, forks
//mutex initialize forks, print, left and right fork
//init value of info->phils
bool init_whole(t_data *info)
{
    if (!init_alloc(info))
        return (false);
    if (!init_mutex(info))
        return (false);
    if (!init_phils(info))
        return (false);
    return (true);
}