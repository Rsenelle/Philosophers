/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:47:13 by rsenelle          #+#    #+#             */
/*   Updated: 2022/04/26 17:48:54 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_struct(t_data *s_data, char **argv)
{
	s_data->start = 0;
	s_data->number_of_philosophers = 0;
	s_data->time_to_die = 0;
	s_data->time_to_eat = 0;
	s_data->time_to_sleep = 0;
	s_data->last_arg = 0;
	s_data->number_of_philosophers = ft_atoi_philo(argv[1]);
	s_data->time_to_die = ft_atoi_philo(argv[2]);
	s_data->time_to_eat = ft_atoi_philo(argv[3]);
	s_data->time_to_sleep = ft_atoi_philo(argv[4]);
	if (argv[5])
		s_data->last_arg = ft_atoi_philo(argv[5]);
	if (check_atoi(s_data) == -1)
	{
		write (2, "Wrong argument\n", 15);
		return (-1);
	}
	if (pthread_mutex_init(&s_data->print_mutex, NULL))
	{
		write(2, "Forks init error\n", 17);
		return (-1);
	}
	return (0);
}

int	check_atoi(t_data *s_data)
{
	if (s_data->number_of_philosophers == -1)
		return (-1);
	if (s_data->time_to_die == -1)
		return (-1);
	if (s_data->time_to_eat == -1)
		return (-1);
	if (s_data->time_to_sleep == -1)
		return (-1);
	if (s_data->last_arg == -1)
		return (-1);
	return (0);
}
