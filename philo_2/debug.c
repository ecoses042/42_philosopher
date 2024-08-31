#include "philosopher.h"

//debug function
//print out all the element in the given s_data
void	print_t_data(t_data param)
{
	printf("number of philosopher: %d\n", param.n_phil);
	printf("die time: %d\n", param.t_die);
	printf("eat time: %d\n", param.t_eat);
	printf("sleep time: %d\n",param.t_sleep);
	printf("repetition: %d\n",param.t_rep);
	printf("current rep: %d\n", param.all_eat_count / param.n_phil);
	if (!param.phils)
		printf("check the phils\n");
}

//debug function
//printout value of single philosopher
void	print_phil(t_phil *param)
{
	printf("index: %d\n",param->n);
}
