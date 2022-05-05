/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:34:32 by rsenelle          #+#    #+#             */
/*   Updated: 2022/04/27 15:34:47 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long int	ft_time(void)
{
	long			start;
	struct timeval	time;

	gettimeofday(&time, NULL);
	start = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (start);
}

void	usleep_fix(long must_time)
{
	long	time;

	time = ft_time();
	while (ft_time() < must_time + time)
		usleep(300);
}
