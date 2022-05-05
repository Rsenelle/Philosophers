/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:53:03 by rsenelle          #+#    #+#             */
/*   Updated: 2022/04/27 15:00:58 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialization_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc (sizeof(pthread_mutex_t) * \
							data->number_of_philosophers);
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
		{
			printf("Forks init error");
			return (-1);
		}
		i++;
	}
	return (0);
}

static void	philo_init(t_data *data, int i)
{
	data->philos[i].id = i + 1;
	data->philos[i].data = data;
	data->philos[i].eat_last = ft_time();
	if (data->last_arg)
		data->philos[i].eat_count = data->last_arg;
	else
		data->philos[i].eat_count = -1;
		data->philos[i].left_fork = &(data->forks[i]);
	if (i == data->number_of_philosophers - 1)
		data->philos[i].right_fork = &(data->forks[0]);
	else
		data->philos[i].right_fork = &(data->forks[i + 1]);
}

int	philo_detach(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_detach(data->philos[i].philo))
		{
			write (2, "Detach error\n", 13);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	philo_thread_create(t_data *data)
{
	int	i;

	i = 0;
	data->start = ft_time();
	data->philos = malloc (sizeof(t_philo) * data->number_of_philosophers);
	if (initialization_mutex(data) == -1)
		return (-1);
	while (i < data->number_of_philosophers)
	{
		philo_init(data, i);
		if (pthread_create(&data->philos[i].philo, NULL, life_cycle, \
			&data->philos[i]))
		{
			printf("Thread creating error");
			return (-1);
		}
		usleep(30);
		i += 2;
		if (i >= data->number_of_philosophers && i % 2 == 0)
			i = 1;
	}
	if (philo_detach(data) < 0)
		return (-1);
	return (0);
}
