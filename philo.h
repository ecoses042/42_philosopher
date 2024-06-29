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

#define INVALUD_INPUT "Cannot be converted into int."
#define INVALUD_INPUT2 "Invalid input."
#define MUTEXALLOC_FAIL "Failed allocating mutex."
#define THREAD_FAIL "failed allocating threads"

#define SLEEP "is sleeping"
#define EAT "is eating"
#define THINK "is thinking"
#define DEATH "died"
#define FORK "has taken a fork."

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
 
 //free function
void ft_exit(t_data *info);

//error output
bool print_error(char *str, t_data *info);

//utility
long	ft_atoi(const char *str);
int	get_time(void);

//input error handling
bool is_valid_char_input(char **av);
bool init_arg(t_data *info, int ac, char **av);

//init_thread
bool init_mutex(t_data *info);
bool init_thread(t_data *info);

//special case


#endif