#include "../philo.h"

//sudo code for phil_action
//mutex lock left and right fork
//eat, mutex free forks
//reset death timer
//if status is eat, sleep for required time, change status to sleep
//think for a set amount of time and if fork is not available, think for some more
//think->check death->fork->eat->check->sleep->think
void *routine(void *ptr)
{

}

void *monitor(void *ptr)
{

}

//sudo code for init_thread
//bool init_thread(t_data *info)
//pthread_create until info->p_num using phil_action function
//do not forget to mutex_lock and free forks when pthread_create
//use pthread_join to merge it into main thread
bool init_thread(t_data *info)
{
    int i;
    pthread_t view;

    i = -1;
    if (info->p_rep > 0)
    {
        if (pthread_create(&view, NULL, &monitor, info->phils[0]))
            return (print_error(THREAD_FAIL, info));
    }
    while (++i < info->p_num)
    {
        if (pthread_create(&info->thds[i], NULL, &routine, info->phils[i]))
            return (print_error(THREAD_FAIL, info));
    }
    i = -1;
    while (++i < info->p_num)
    {
        if (pthread_join(&info->thds[i], NULL))
            return (print_error(THREAD_JOIN, info));
    }
    return (true);
}