//
// Created by Romaine Senelle on 3/24/22.
//

#include "philo.h"

void ft_eat(t_philo *s_philo)
{
	s_philo->eat_last = ft_time();
	pthread_mutex_lock(&s_philo->data->print_mutex);
	printf("%ld %d is eating\n", \
		ft_time() - s_philo->data->start, s_philo->id);
	pthread_mutex_unlock(&s_philo->data->print_mutex);
	usleep_fix(s_philo->data->time_to_eat);
	pthread_mutex_unlock(s_philo->left_fork);
	pthread_mutex_unlock(s_philo->right_fork);
	if (s_philo->eat_count)
		s_philo->eat_count--;
}

void ft_sleep(t_philo *s_philo)
{
	pthread_mutex_lock(&s_philo->data->print_mutex);
	printf("%ld %d is sleeping\n", \
		ft_time() - s_philo->data->start, s_philo->id);
	pthread_mutex_unlock(&s_philo->data->print_mutex);
	usleep_fix(s_philo->data->time_to_sleep);
}

void ft_think(t_philo *s_philo)
{
	pthread_mutex_lock(&s_philo->data->print_mutex);
	printf("%ld %d is thinking\n", \
		ft_time() - s_philo->data->start, s_philo->id);
	pthread_mutex_unlock(&s_philo->data->print_mutex);
//	usleep_fix((s_philo->data->time_to_die - s_philo->data->time_to_eat - s_philo->data->time_to_sleep));
}

void ft_take_forks(t_philo *s_philo)
{
	pthread_mutex_lock(s_philo->left_fork);
	pthread_mutex_lock(&s_philo->data->print_mutex);
	printf("%ld %d has taken a fork\n", \
		ft_time() - s_philo->data->start, s_philo->id);
	pthread_mutex_unlock(&s_philo->data->print_mutex);
	pthread_mutex_lock(s_philo->right_fork);
	pthread_mutex_lock(&s_philo->data->print_mutex);
	printf("%ld %d has taken a fork\n", \
		ft_time() - s_philo->data->start, s_philo->id);
	pthread_mutex_unlock(&s_philo->data->print_mutex);

}


void *life_cycle(void *philo)
{
	t_philo *s_philo;

	s_philo = (t_philo *)philo;
	while(1)
	{
		ft_take_forks(s_philo);
		ft_eat(s_philo);
		ft_sleep(s_philo);
		ft_think(s_philo);
		if (!s_philo->eat_count)
		{
//			printf("finish %d\n", s_philo->id);
			s_philo->data->common_eat--;
			break ;
		}
	}
	return 0;
}

int initialization_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc (sizeof(pthread_mutex_t) * data->number_of_philosophers);
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
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].eat_last = ft_time();
		if (data->number_of_times_each_philosopher_must_eat)
			data->philos[i].eat_count = data->number_of_times_each_philosopher_must_eat;
		else
			data->philos[i].eat_count = -1;
		data->philos[i].left_fork = &(data->forks[i]);
		if (i == data->number_of_philosophers - 1)
			data->philos[i].right_fork = &(data->forks[0]);
		else
			data->philos[i].right_fork = &(data->forks[i + 1]);
		if (pthread_create(&data->philos[i].philo, NULL, life_cycle, &data->philos[i]))
		{
			printf("Thread creating error");
			return (-1);
		}
		usleep(30);
		i+=2;
		if (i >= data->number_of_philosophers && i % 2 == 0)
			i = 1;
	}
	return (0);
}
