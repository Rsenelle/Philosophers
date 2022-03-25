//
// Created by Romaine Senelle on 3/24/22.
//

#include "philo.h"

int	philo_without_time_of_eating(char **argv, int argc)
{
	long int new_time;
	struct timeval time;
	gettimeofday(&time, NULL);
	new_time = time.tv_sec * 1000 + time.tv_usec / 1000;
}

