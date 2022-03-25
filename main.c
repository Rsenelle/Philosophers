#include "philo.h"

int main(int argc, char **argv)
{
	t_philo s_philo;

	if (argc > 4)
	{
		if (init_struct(&s_philo, argv) == -1)
			return (-1);
		if (argc == 5)
			philo_without_time_of_eating(argv, argc);
		else if (argc == 6)
			philo_with_time_of_eating();
		else
		{
			ft_putendl_fd("Wrong number of arguments", 2);
			return (1);
		}
	}
	return 0;
}