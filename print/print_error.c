#include "../philo.h"


//function to print error and free the t_data
bool print_error(char *str, t_data *info)
{
    printf("%s\n",str);
    if (info)
        ft_exit(info);
    return (false);
}