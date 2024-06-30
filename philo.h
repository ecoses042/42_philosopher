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
#define THREAD_JOIN "failed connecting to main thread"

#define SLEEP "is sleeping"
#define EAT "is eating"
#define THINK "is thinking"
#define DEATH "died"
#define FORK "has taken a fork."

struct s_data;

typedef struct s_phil{
    pthread_t check;
    int id;
    struct s_data *data;
    bool eat_status;
    bool think_status;
    bool sleep_status;
    int time_until_die;
    bool dead;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
} t_phil;

typedef struct s_data{
    t_phil *phils;
    pthread_t *thds;
    int p_num;
    int p_die_time;
    int p_eat_time;
    int p_sleep_time;
    int current_rep;
    int current_time;
    int start_time;
    int p_rep;
    bool dead;
    pthread_mutex_t *forks;
    pthread_mutex_t lock;
    pthread_mutex_t print;
}t_data;
 
 //free function
void ft_exit(t_data *info);

//error output
bool print_error(char *str, t_data *info);

//utility
long	ft_atoi(const char *str);
int	get_time(void);
int find_left_fork(int index, t_data *info);
void action_print(char *str, t_phil *phil);

//input error handling
bool is_valid_char_input(char **av);
bool init_arg(t_data *info, int ac, char **av);

//init_thread
bool init_whole(t_data *info);
bool init_thread(t_data *info);

//special case
bool case_one(const t_data *info);



//debug function, delete when done
void dump(t_data *info);

#endif