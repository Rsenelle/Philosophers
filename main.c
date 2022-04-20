#include "philo.h"

int main(int argc, char **argv)
{
	t_data s_data;

	if (argc == 5 || argc == 6)
	{
		if (init_struct(&s_data, argv) == -1)
			return (-1);
		philo_thread_create(&s_data);
		main_cycle(&s_data);
	}
	else
	{
		ft_putendl_fd("Wrong number of arguments", 2);
		return (-1);
	}
	return 0;
}

void	main_cycle(t_data *s_data)
{
	int i;

	i = 0;
	while(1)
	{
			if (i >= s_data->number_of_philosophers - 1)
				i = 0;
			if (!s_data->common_eat && s_data->number_of_times_each_philosopher_must_eat)
			{
				pthread_mutex_lock(&s_data->print_mutex);
				printf("All philos have eaten\n");
				break;
			}
			if ((ft_time() - s_data->philos[i].eat_last > s_data->time_to_die) && s_data->philos[i].eat_count)
			{
				pthread_mutex_lock(&s_data->print_mutex);
				printf("%ld %d is dead\n", ft_time() - s_data->start, s_data->philos[i].id);
				break;
			}
			if (ft_time() - s_data->philos[i].eat_last > s_data->time_to_die) {
//				int j = -1;
//				while(++j < s_data->number_of_philosophers)
//					printf("philo %d - eat %d\n", s_data->philos[j].id, s_data->philos[j].eat_count);
//				printf("common eat %d\n", s_data->common_eat);
				printf("All philos have eaten\n");
				break ;
			}
			i++;
	}
}