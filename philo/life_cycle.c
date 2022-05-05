/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:13:22 by rsenelle          #+#    #+#             */
/*   Updated: 2022/04/27 14:57:52 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_cycle(void *philo)
{
	t_philo	*s_philo;

	s_philo = (t_philo *)philo;
	while (1)
	{
		ft_take_forks(s_philo);
		ft_eat(s_philo);
		ft_sleep(s_philo);
		ft_think(s_philo);
		if (!s_philo->eat_count)
			break ;
	}
	return (0);
}

void	ft_eat(t_philo *s_philo)
{
	s_philo->eat_last = ft_time();
	print("is eating", s_philo);
	usleep_fix(s_philo->data->time_to_eat);
	pthread_mutex_unlock(s_philo->left_fork);
	pthread_mutex_unlock(s_philo->right_fork);
	if (s_philo->eat_count)
		s_philo->eat_count--;
}

void	ft_sleep(t_philo *s_philo)
{
	print("is sleeping", s_philo);
	usleep_fix(s_philo->data->time_to_sleep);
}

void	ft_think(t_philo *s_philo)
{
	print("is thinking", s_philo);
}

void	ft_take_forks(t_philo *s_philo)
{
	pthread_mutex_lock(s_philo->left_fork);
	print ("has taken a fork", s_philo);
	pthread_mutex_lock(s_philo->right_fork);
	print ("has taken a fork", s_philo);
}
