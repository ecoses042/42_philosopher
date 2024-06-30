#include "../philo.h"

int find_left_fork(int index, t_data *info)
{
    if (index == info->p_num - 1)
        return (0);
    else
        return (index + 1);
}