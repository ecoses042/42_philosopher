#include "philo.h"

int main(int ac, char **av)
{
    t_data info;

    if (ac < 5 || ac > 6)
        return (1);
    if (!is_valid_char_input(av))
        return (1);
    if (!init_whole(&info, ac, av))
        return (1);
    if (info.p_num == 1)
        return (case_one(&info));
    else
        init_thread(&info);
    
    return (0);
}