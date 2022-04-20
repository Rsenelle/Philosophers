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

long int	ft_time(void)
{
	long start;
	struct timeval time;

	gettimeofday(&time, NULL);
	start = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (start);
}

void	usleep_fix(long must_time)
{
	long	time;

	time = ft_time();
	while (ft_time() - time < must_time)
		usleep(100);
}

//void	ft_putnbr_fd(int n, int fd)
//{
//	char	s;
//	{
//		if (n == -2147483648)
//		{
//			write(fd, "-", 1);
//			write(fd, "2", 1);
//			ft_putnbr_fd(147483648, fd);
//		}
//		else if (n < 0)
//		{
//			write(fd, "-", 1);
//			n *= -1;
//			ft_putnbr_fd(n, fd);
//		}
//		else if (n < 10)
//		{
//			s = n + '0';
//			write(fd, &s, 1);
//		}
//		else
//		{
//			ft_putnbr_fd(n / 10, fd);
//			ft_putnbr_fd(n % 10, fd);
//		}
//	}
//}