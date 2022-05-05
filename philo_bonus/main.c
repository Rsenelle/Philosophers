/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:35:54 by rsenelle          #+#    #+#             */
/*   Updated: 2022/04/27 15:36:15 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	s_data;

	if (argc == 5 || argc == 6)
	{
		if (init_struct(&s_data, argv) == -1)
			exit (1);
		init(&s_data);
		kill_pid(&s_data);
	}
	else
	{
		write(2, "Wrong number of arguments\n", 26);
		return (1);
	}
	return (0);
}
