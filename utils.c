//
// Created by Romaine Senelle on 3/24/22.
//

#include "philo.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write (fd, &s[i], 1);
			i++;
		}
		write (fd, "\n", 1);
	}
}

int	ft_error(char *s)
{
	if (s)
	{
		ft_putendl_fd(s, 2);
		return (1);
	}
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
