//
// Created by Romaine Senelle on 3/24/22.
//

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>


typedef struct	s_philo
{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
}				t_philo;

void	ft_putendl_fd(char *s, int fd);
int		ft_error(char *s);
int		philo_without_time_of_eating(char **argv, int argc);
int 	init_struct(t_philo *s_philo, char **argv);
int		ft_atoi_philo(char *str);
int		check_atoi(t_philo *s_philo);

#endif