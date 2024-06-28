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

typedef struct s_data;

typedef struct s_phil{
    int id;
    struct s_data *data;
    pthread_t thread_phil;
    bool eat_status;
    bool think_status;
    bool sleep_status;
    int meal_num;
    int time_until_die;
    bool dead;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
} t_phil;

typedef struct s_data{
    t_phil *phil;
    int p_num;
    int p_die_time;
    int p_eat_time;
    int p_sleep_time;
    int current_rep;
    int p_rep;
    bool dead;
    pthread_mutex_t *forks;
    pthread_mutex_t print;
}t_data;
 
//input_error
bool is_valid_char_input(char **av);
//utility
long	ft_atoi(const char *str);

//init philo
bool init_whole(t_data *info, int ac, char **av);
bool case_one(const t_data *info);

//process related functions

#endif