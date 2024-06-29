#include "philo.h"

int main(int ac, char **av)
{
    t_data info;

    if (ac < 5 || ac > 6)
        return (1);
    if (!is_valid_char_input(av))
        return (1);
    if (!init_arg(&info, ac, av))
        return (1);
    if (!init_mutex(&info))
        return (1);
    if (!init_thread(&info))
        return (1);
    ft_exit(&info);
    return (0);
}