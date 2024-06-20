#include "../philo.h"

//
bool init_data(t_data *info, const int ac,const char **av)
{
    info->p_num = (int)ft_atoi(av[1]);
    info->p_die_time = (int)ft_atoi(av[2]);
    info->p_eat_time = (int)ft_atoi(av[3]);
    info->p_sleep_time = (int)ft_atoi(av[4]);
    if (ac == 6)
        info->p_rep = (int)ft_atoi(av[5]);
    else
        info->p_rep = -1;
}

bool init_whole(t_data *info, const int ac, const char **av)
{
    if (!init_data(info,ac,av))
        return (false);
    if (!init_philo(info))
        return (false);
}