/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:41:15 by lcavallu          #+#    #+#             */
/*   Updated: 2022/01/27 17:39:56 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_sleep(int time_eat, t_data *d)
{
	int		i;
	_Bool	philo_died;

	i = 100;
	pthread_mutex_lock(&d->mutex_die);
	philo_died = d->philo_died;
	pthread_mutex_unlock(&d->mutex_die);
	while (i < time_eat && philo_died == NO)
	{
		pthread_mutex_lock(&d->mutex_die);
		philo_died = d->philo_died;
		pthread_mutex_unlock(&d->mutex_die);
		usleep(100 * 1000);
		i += 100;
	}
	if (philo_died == NO)
		usleep((time_eat - (i - 100)) * 1000);
	return (SUCCESS);
}

int	create_thread(t_philo *philo, t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nb_philo)
	{
		usleep(100);
		if (pthread_create(&(philo[i]).thread, NULL, &routine, &philo[i]) != 0)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	join_thread(t_philo *philo, t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

void	check_death_inside(int i, t_data *d, t_philo *philo)
{
	int	time_now;

	pthread_mutex_unlock(&d->mutex_die);
	usleep(100);
	pthread_mutex_lock(&d->mutex_die);
	time_now = (get_time() - d->time_start) - philo[i].last_meal;
	pthread_mutex_unlock(&d->mutex_die);
	if (time_now > d->die)
	{
		pthread_mutex_lock(&d->mutex_die);
		d->philo_died = YES;
		pthread_mutex_unlock(&d->mutex_die);
		pthread_mutex_lock(&d->mutex_print);
		printf("%ldms     |%i died\n", get_time() - d->time_start, i + 1);
		pthread_mutex_unlock(&d->mutex_print);
	}
}

int	check_death(t_data *d, t_philo *philo)
{
	int	i;

	i = 0;
	while (d->philo_died == NO && ((check_meals(d, philo, i)
				|| d->max_eat == -1) || d->nb_philo == 1))
	{
		pthread_mutex_lock(&d->mutex_die);
		if ((d->nb_philo != 1 && philo[i].meal_eaten > 0) || d->nb_philo == 1)
			check_death_inside(i, d, philo);
		else
			pthread_mutex_unlock(&d->mutex_die);
		if (i == (d->nb_philo - 1))
			i = 0;
		else
			i++;
	}
	return (NO);
}
