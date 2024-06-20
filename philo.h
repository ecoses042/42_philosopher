#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data{
    int p_num;
    int p_die_time;
    int p_eat_time;
    int p_sleep_time;
    int p_rep;
}t_data;
 
//input_error
bool is_valid_char_input(const char **av);
//utility
long	ft_atoi(const char *str);

//init philo
bool init_whole(t_data *info, const int ac, const char **av);

#endif