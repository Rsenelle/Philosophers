/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:32:15 by rsenelle          #+#    #+#             */
/*   Updated: 2022/04/27 15:33:30 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/wait.h>

# define WELL_FED	2

typedef struct s_philo
{
	pthread_t		philos_death;
	int				id;
	int				eat_count;
	struct s_data	*data;
	long			eat_last;
	pid_t			pid;
}				t_philo;

typedef struct s_data
{
	int			num_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			last_arg;
	long		start;
	int			status;
	sem_t		*forks;
	sem_t		*print;
	t_philo		*philos;
}				t_data;

void		ft_putendl_fd(char *s, int fd);
long int	ft_time(void);
void		philo_create(t_data *s_data);
int			init_struct(t_data *s_data, char **argv);
int			ft_atoi_philo(char *str);
int			check_atoi(t_data *s_data);
void		ft_putnbr_fd(long int n);
void		main_cycle(t_data *s_data);
void		usleep_fix(long must_time);
void		print(char *s, t_philo *s_philo);
void		ft_eat(t_philo *s_philo);
void		ft_sleep(t_philo *s_philo);
void		ft_think(t_philo *s_philo);
void		ft_take_forks(t_philo *s_philo);
void		*monitoring(void *philo);
void		life_cycle(t_philo *s_philo);
void		kill_pid(t_data *s_data);
void		init(t_data *s_data);

#endif