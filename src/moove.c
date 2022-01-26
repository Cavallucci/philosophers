/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:41:15 by lcavallu          #+#    #+#             */
/*   Updated: 2022/01/26 18:10:00 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	put_down_forks(t_data *d, t_philo *philo)
{
	pthread_mutex_unlock(&d->forks[philo->right_fork]);
	pthread_mutex_unlock(&d->forks[philo->left_fork]);
	return (SUCCESS);
}

int	take_fork(t_data *d, t_philo *philo)
{
	long int	time;

	pthread_mutex_lock(&d->forks[philo->left_fork]);
	if (philo_dead(d) == NO)
	{
		time = get_time() - d->time_start;
		pthread_mutex_lock(&d->mutex_print);
		printf("%ldms     |%d has taken a fork\n", time, philo->id + 1);
		pthread_mutex_unlock(&d->mutex_print);
	}
	if (philo->left_fork == philo->right_fork)
		return (ERROR);
	pthread_mutex_lock(&d->forks[philo->right_fork]);
	if (philo_dead(d) == NO)
	{
		time = get_time() - d->time_start;
		pthread_mutex_lock(&d->mutex_print);
		printf("%ldms     |%d has taken a fork\n", time, philo->id + 1);
		pthread_mutex_unlock(&d->mutex_print);
	}
	return (SUCCESS);
}

int	is_eating(t_data *d, t_philo *philo)
{
	long int	time;

	pthread_mutex_lock(&d->mutex_die);
	philo->last_meal = get_time() - d->time_start;
	pthread_mutex_unlock(&d->mutex_die);
	if (philo_dead(d) == NO && d->nb_philo != 1)
	{
		time = get_time() - d->time_start;
		pthread_mutex_lock(&d->mutex_print);
		printf("%ldms     |%d is eating\n", time, philo->id + 1);
		pthread_mutex_unlock(&d->mutex_print);
	}
	pthread_mutex_lock(&d->mutex_die);
	philo->meal_eaten++;
	pthread_mutex_unlock(&d->mutex_die);
	ft_sleep(d->eat, d);
	return (SUCCESS);
}

int	is_sleeping(t_data *d, t_philo *philo)
{
	long int	time;

	if (philo_dead(d) == NO)
	{
		time = get_time() - d->time_start;
		pthread_mutex_lock(&d->mutex_print);
		printf("%ldms     |%d is sleeping\n", time, philo->id + 1);
		pthread_mutex_unlock(&d->mutex_print);
	}
	ft_sleep(d->sleep, d);
	return (SUCCESS);
}

int	is_thinking(t_data *d, t_philo *philo)
{
	long int	time;

	if (d->philo_died == NO)
	{
		time = get_time() - d->time_start;
		pthread_mutex_lock(&d->mutex_print);
		printf("%ldms     |%d is thinking\n", time, philo->id + 1);
		pthread_mutex_unlock(&d->mutex_print);
	}
	return (SUCCESS);
}
