//
// Created by Romaine Senelle on 3/24/22.
//

#include "philo.h"

int	init_struct(t_philo *s_philo, char **argv)
{
	s_philo->number_of_philosophers = 0;
	s_philo->time_to_die = 0;
	s_philo->time_to_eat = 0;
	s_philo->time_to_sleep = 0;
	s_philo->number_of_times_each_philosopher_must_eat = 0;
	s_philo->number_of_philosophers = ft_atoi_philo(argv[1]);
	s_philo->time_to_die = ft_atoi_philo(argv[2]);
	s_philo->time_to_eat = ft_atoi_philo(argv[3]);
	s_philo->time_to_sleep = ft_atoi_philo(argv[4]);
	if (argv[5])
		s_philo->number_of_times_each_philosopher_must_eat = ft_atoi_philo(argv[5]);
	if (check_atoi(s_philo) == -1)
	{
		ft_putendl_fd("Wrong argument", 2);
		return (-1);
	}
	return (0);
}

int	check_atoi(t_philo *s_philo)
{
	if (s_philo->number_of_philosophers == -1)
		return (-1);
	if (s_philo->time_to_die == -1)
		return (-1);
	if (s_philo->time_to_eat == -1)
		return (-1);
	if (s_philo->time_to_sleep == -1)
		return (-1);
	if (s_philo->number_of_times_each_philosopher_must_eat == -1)
		return (-1);
	return (0);
}