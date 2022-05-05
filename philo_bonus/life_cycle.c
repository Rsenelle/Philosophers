/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:35:12 by rsenelle          #+#    #+#             */
/*   Updated: 2022/04/27 15:35:30 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	life_cycle(t_philo *s_philo)
{
	if (pthread_create(&s_philo->philos_death, NULL, monitoring, s_philo) < 0)
	{
		exit (1);
	}
	while (1)
	{
		ft_take_forks(s_philo);
		ft_eat(s_philo);
		ft_sleep(s_philo);
		ft_think(s_philo);
		if (!s_philo->eat_count)
			exit (2);
	}
}

void	ft_eat(t_philo *s_philo)
{
	s_philo->eat_last = ft_time();
	print("is eating", s_philo);
	usleep_fix(s_philo->data->time_to_eat);
	sem_post(s_philo->data->forks);
	sem_post(s_philo->data->forks);
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
	sem_wait(s_philo->data->forks);
	print ("has taken a fork", s_philo);
	sem_wait(s_philo->data->forks);
	print ("has taken a fork", s_philo);
}
