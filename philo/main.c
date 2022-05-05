/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:52:44 by rsenelle          #+#    #+#             */
/*   Updated: 2022/04/27 14:57:17 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	s_data;

	if (argc == 5 || argc == 6)
	{
		if (init_struct(&s_data, argv) == -1)
			return (-1);
		if (philo_thread_create(&s_data) == -1)
			return (-1);
		main_cycle(&s_data);
	}
	else
	{
		printf("Wrong number of arguments");
		return (-1);
	}
	return (0);
}

static int	check(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (data->philos[i++].eat_count)
			return (0);
	}
	return (1);
}

void	main_cycle(t_data *s_data)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i >= s_data->number_of_philosophers - 1)
			i = 0;
		if (check(s_data) && s_data->last_arg)
		{
			pthread_mutex_lock(&s_data->print_mutex);
			printf("All philos have eaten\n");
			break ;
		}
		if ((ft_time() - s_data->philos[i].eat_last > s_data->time_to_die))
		{
			pthread_mutex_lock(&s_data->print_mutex);
			printf("%ld %d is dead\n", ft_time() - s_data->start, \
					s_data->philos[i].id);
			break ;
		}
			i++;
	}
}
