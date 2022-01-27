/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:41:15 by lcavallu          #+#    #+#             */
/*   Updated: 2022/01/27 17:39:24 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	nb;

	nb = 0;
	sign = 1;
	while (*nptr == '\f' || *nptr == '\t' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\v' || *nptr == ' ')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + *nptr - 48;
		nptr++;
	}
	if (nb * sign > 2147483647)
		return (-1);
	return ((int)nb * sign);
}

int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(unsigned char *)(s + i++) = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	array = (void *)malloc(size * count);
	if (!array)
		return (NULL);
	ft_bzero(array, size * count);
	return (array);
}

int	check_meals(t_data *d, t_philo *philo, int i)
{
	pthread_mutex_lock(&d->mutex_die);
	if ((d->max_eat != 1 && philo[i].meal_eaten < d->max_eat)
		|| d->max_eat == 1)
	{
		pthread_mutex_unlock(&d->mutex_die);
		return (SUCCESS);
	}
	else
	{
		pthread_mutex_unlock(&d->mutex_die);
		return (ERROR);
	}
}
