#include "philo.h"

void dump(t_data *info)
{
    printf("number of philosophers: %d\n", info->p_num);
    printf("time given til death: %d\n", info->p_die_time);
    printf("time for eat: %d\n",info->p_eat_time);
    printf("timme to sleep: %d\n", info->p_sleep_time);
    printf("current rep: %d\n", info->current_rep);
    printf("required rep: %d\n", info->p_rep);
    printf("check if there's dead: %d\n", info->dead);
    int i = -1;
    while (++i < info->p_num)
    {
        printf("id: %d\n", info->phils[i].id);
        printf("eating? :%d\n",info->phils[i].eat_status);
        printf("sleeping?: %d\n",info->phils[i].sleep_status);
        printf("thinking? :%d\n",info->phils[i].think_status);
        printf("time left to die: %d\n",info->phils[i].time_until_die);
        printf("start_tiem: %d\n",info->phils[i].start_time);
        printf("is he dead: %d\n", info->phils[i].dead);
    }
    printf("end of the list.");
}