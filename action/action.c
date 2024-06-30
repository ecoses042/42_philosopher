#include "../philo.h"

void action_print(char *str, t_phil *phil)
{
    int current_time;

    current_time = get_time() - phil->data->start_time;
    printf("%d %d %s", current_time,phil->id, str);   
}

//update the death timer of phil
//if death, print death and return true
//if not, return false
void action_sleep()
{
    
}

//update the death timer of phil
//mutex lock and print fork
//if death, print death and return true
//if not, print eat
//drop fork and return false
bool action_eat()
{

}


bool action_think()
{

}