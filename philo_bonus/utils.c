/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:33:52 by rsenelle          #+#    #+#             */
/*   Updated: 2022/04/27 15:35:00 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_srtlen(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	print(char *s, t_philo *s_philo)
{
	sem_wait(s_philo->data->print);
	ft_putnbr_fd(ft_time() - s_philo->data->start);
	write(1, " ", 1);
	ft_putnbr_fd(s_philo->id);
	write(1, " ", 1);
	write (1, s, ft_srtlen(s));
	write(1, "\n", 1);
	sem_post(s_philo->data->print);
}

int	ft_atoi_philo(char *str)
{
	int			i;
	long int	k;

	i = 0;
	k = 0;
	while (((str[i] >= 7) && (str[i] <= 13)) || (str[i] == ' '))
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = (k * 10) + str[i] - '0';
		if (k > 2147483647)
			return (-1);
		if (k < -2147483648)
			return (-1);
		i++;
	}
	return (k);
}

void	ft_putnbr_fd(long int n)
{
	char	s;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		ft_putnbr_fd(n);
	}
	else if (n < 10)
	{
		s = n + '0';
		write(1, &s, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10);
		ft_putnbr_fd(n % 10);
	}
}
