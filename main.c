#include "philo.h"

int main(int ac, char **av)
{
    t_data info;

    if (ac < 5 || ac > 6)
        return (1);
    if (!is_valid_char_input(av))
        printf("this is not int\n");
        //return (1);
    if (!init_whole(&info, ac, av))
        printf("it is not valud\n");
        //return (1);
    if (!init_mutex(&info))
        printf("mutex allocation failed\n");
        //return (1);
    
    //ft_exit();
        
    return (0);
}