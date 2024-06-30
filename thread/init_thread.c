#include "../philo.h"

//thread function to check philosopher thread status
//if dead, update the status to t_data to merge the thread
void *catch_up(void *ptr)
{
    t_phil *philo;

    philo = (t_phil *)ptr;
    while (!philo->data->dead)
    {
        if (get_time() > philo->time_until_die && philo->data->dead)
        {
            pthread_mutex_lock(&philo->data->print);
            action_print(DEATH, philo);
            pthread_mutex_unlock(&philo->data->print);
            philo->dead = true;
            philo->data->dead = true;
        }
    }
    return (0);
}
//sudo code 
//mutex lock left and right fork
//eat, mutex free forks
//reset death timer
//if status is eat, sleep for required time, change status to sleep
//think for a set amount of time and if fork is not available, think for some more
//think->check death->fork->eat->check->sleep->think
void *routine(void *ptr)
{
    int current_rep;
    int max_rep;
    t_phil *philo;

    philo = (t_phil *)ptr;
    current_rep = philo->data->current_rep;
    max_rep = philo->data->p_rep;
    philo->data->start_time = get_time();
    philo->data->current_time = philo->data->start_time;
    philo->time_until_die = philo->data->start_time + philo->data->p_die_time;
    //create thread to check death condition for this philosopher
    pthread_create(philo->check, NULL, &catch_up, philo);
    while (!philo->dead || current_rep != max_rep)
    {

    }
    return (0);
}

//set data->dead true if repetition is complete
void *monitor(void *ptr)
{
    int max_rep;
    t_phil *philo;

    philo = (t_phil *)ptr;
    max_rep = philo->data->p_rep;
    while (philo->data->current_rep != max_rep)
    {
        //code for counting reps
    }
    return (0);
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
        if (pthread_create(&view, NULL, &monitor, &info->phils[0]))
            return (print_error(THREAD_FAIL, info));
    }
    while (++i < info->p_num)
    {
        if (pthread_create(&info->thds[i], NULL, &routine, &info->phils[i]))
            return (print_error(THREAD_FAIL, info));
    }
    i = -1;
    while (++i < info->p_num)
    {
        if (pthread_join(info->thds[i], NULL))
            return (print_error(THREAD_JOIN, info));
    }
    return (true);
}