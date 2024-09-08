#include "philosopher.h"

int	main(int ac, char **av)
{
	t_data	info;

	if (!is_valid_char_input(ac, av))
		return (1);
	if (!init_info(ac, av, &info))
		return (1);
	if (!init_philo(&info))
		return (1);
	manage_thread(&info);
	data_mutex_destroy(&info, 4, NULL);
	return (0);
}
