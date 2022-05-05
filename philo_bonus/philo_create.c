/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:25:54 by rsenelle          #+#    #+#             */
/*   Updated: 2022/04/27 15:30:05 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init(t_data *s_data)
{
	s_data->philos = malloc (sizeof(t_philo) * s_data->num_of_philos);
	sem_unlink("forks");
	sem_unlink("print");
	s_data->forks = sem_open("forks", O_CREAT, 0644, s_data->num_of_philos);
	s_data->print = sem_open("print", O_CREAT, 0644, 1);
	philo_create(s_data);
}

void	*monitoring(void *philo)
{
	t_philo	*s_philo;

	s_philo = (t_philo *)philo;
	while (1)
	{
		if (ft_time() - s_philo->eat_last > s_philo->data->time_to_die)
		{
			sem_wait(s_philo->data->print);
			printf("%ld %d is dead\n", ft_time() - s_philo->data->start, \
					s_philo->id);
			exit (1);
		}
	}
}

void	philo_create(t_data *s_data)
{
	int		i;
	pid_t	pid;

	i = 0;
	s_data->start = ft_time();
	while (i++ < s_data->num_of_philos)
	{
		s_data->philos[i].id = i + 1;
		s_data->philos[i].data = s_data;
		s_data->philos[i].eat_last = ft_time();
		if (s_data->last_arg)
			s_data->philos[i].eat_count = s_data->last_arg;
		else
			s_data->philos[i].eat_count = -1;
		pid = fork();
		if (pid < 0)
		{
			write(2, "Fork error\n", 11);
			exit(1);
		}
		if (pid == 0)
			life_cycle(&s_data->philos[i]);
		else
			s_data->philos[i].pid = pid;
	}
}

void	kill_pid(t_data *s_data)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (i < s_data->num_of_philos)
	{
		waitpid(-1, &s_data->status, 0);
		if (WEXITSTATUS(s_data->status) != WELL_FED)
		{
			while (j < s_data->num_of_philos)
			{
				kill(s_data->philos[j].pid, SIGKILL);
				j++;
			}
			return ;
		}
		i++;
	}
	sem_wait(s_data->print);
	printf("All philos have eaten\n");
	return ;
}
