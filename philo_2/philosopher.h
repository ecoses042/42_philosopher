#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

# define INVALID_INPUT "error\nWrong input"
# define ALLOC_ERR "error\nallocation failed"
#define MUTEXALLOC_FAIL "Failed allocating mutex."
#define THREAD_FAIL "failed allocating threads"
#define THREAD_JOIN "failed connecting to main thread"
#define	MAX_REP "philosophers are full\n"
#define SLEEP "is sleeping"
#define EAT "is eating"
#define THINK "is thinking"
#define DEATH "died"
#define FORK "has taken a fork."
struct s_data;

//left fork is given phil's fork
//phil have to get right fork in order to eat
typedef struct s_phil{
	int	n;
	long int	start_time;
	long int	last_eat;
	pthread_t	thread;
	struct s_data *info;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
}t_phil;

//overall data and main thread control
//mutex print for printing one philosopher at a time
//mutex m_die for checking data->death one at a time
//mutex m_all_eat for checking rep reached one at a time
typedef struct s_data{
	int n_phil;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	t_rep;
	int	death;
	int	all_eat_count;
	pthread_mutex_t	print;
	pthread_mutex_t	m_die;
	pthread_mutex_t	m_all_eat;
	t_phil	*phils;
}t_data;
//check input
bool is_valid_char_input(int ac, char **av);
bool	init_info(int ac, char **av, t_data *info);
bool init_philo(t_data *info);

//thread handling
bool	manage_thread(t_data	*info);
bool	ft_one_philo(t_phil *philo);
bool	eat(t_phil *philo);
bool	sleeping(t_phil	*philo);
bool	thinking(t_phil	*philo);
bool	process_dead(t_phil *phil);

//error related functions
bool	print_error(char	*status);
//utility
int	ft_strlen(const	char *a);
long	ft_atoi(const char *str);
long long	get_time();
bool	is_dead(t_phil	*param);
//print current status of the given philosopher
void	print_status(t_phil	*param, int mode);
//destroy mutex of the info by the mode argument
//after, print msg and free info->phils
bool	data_mutex_destroy(t_data	*info, int mode, char *msg);

//debug function
void	print_t_data(t_data param);
void	print_phil(t_phil *param);