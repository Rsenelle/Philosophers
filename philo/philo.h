/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:17:20 by rsenelle          #+#    #+#             */
/*   Updated: 2022/04/27 15:00:55 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		philo;
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				eat_count;
	struct s_data	*data;
	long			eat_last;
}				t_philo;

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				last_arg;
	long			start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	t_philo			*philos;
}				t_data;

void		ft_putendl_fd(char *s, int fd);
long int	ft_time(void);
void		*life_cycle(void *philo);
int			philo_thread_create(t_data *s_data);
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

#endif