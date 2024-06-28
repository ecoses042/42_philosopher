#include "../philo.h"

//sudo code for phil_action
//mutex lock left and right fork
//eat, mutex free forks
//reset death timer
//if status is eat, sleep for required time, change status to sleep
//think for a set amount of time and if fork is not available, think for some more
void *phil_action(void *ptr)
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

    i = 0;
    while (++i <= info->p_num || info->dead == true)
    {
        info->phil->left_fork = &info->forks[i];
        info->phil->right_fork = &info->forks[(i%info->p_num)- 1];
        if (pthread_create(&info->phil[i].thread_phil, NULL, phil_action, &info->phil[i]))
            return (false);
    }
    i = 0;
    while (++i <= info->p_num)
        pthread_join(info->phil[i].thread_phil, NULL);
    return (true);
}