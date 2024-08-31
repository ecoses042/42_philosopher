#include "philosopher.h"

//take input
//if valid, write down info on t_data
//create thread as a number of philosopher given
//main thread works as a supervisor. if 1 sub thread is dead, stop the whole threads
//
int main(int ac, char **av)
{
	t_data info;

	if (!is_valid_char_input(ac, av))
		return (1);
	if (!init_info(ac, av, &info))
		return (1);
	if (!init_philo(&info))
		return (1);
	manage_thread(&info);
	print_t_data(info);
	data_mutex_destroy(&info, 4, NULL);
	return (0);
}

//recreate the init function so that mutex is destroyed
