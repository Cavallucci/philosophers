/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:41:15 by lcavallu          #+#    #+#             */
/*   Updated: 2022/01/21 17:42:36 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    take_fork(t_data *d, t_philo *philo)
{
    long int    time;

    pthread_mutex_lock(&d->forks[philo->left_fork]);
    pthread_mutex_lock(&d->forks[philo->right_fork]);
    pthread_mutex_lock(&d->mutex_print);
    if (d->philo_died == NO)
    {
      time = get_time() - d->time_start;
      printf("%ldms     |%d is taking a fork\n", time, philo->id + 1);
    }
    pthread_mutex_unlock(&d->mutex_print);
    return (SUCCESS);
}

int ft_sleep(int time_eat, t_data *d)
{
    int i;
    _Bool philo_dead;

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
        usleep(100);
}

int    is_eating(t_data *d, t_philo *philo)
{
    long int    time;

    pthread_mutex_lock(&d->mutex_die);
    philo->meal_eaten++;
    pthread_mutex_unlock(&d->mutex_die);
    pthread_mutex_lock(&d->mutex_print);
    if (d->philo_died == NO)
    {
       time = get_time() - d->time_start;
      printf("%ldms     |%d is eating\n", time, philo->id + 1);
    }
    pthread_mutex_unlock(&d->mutex_print);
    ft_sleep(d->eat, d);
    return (SUCCESS);
}

int    put_down_forks(t_data *d, t_philo *philo)
{
    long int    time;

    pthread_mutex_unlock(&d->forks[philo->right_fork]);
    pthread_mutex_unlock(&d->forks[philo->right_fork]);
    pthread_mutex_lock(&d->mutex_print);
    if (d->philo_died == NO)
    {
      time = get_time() - d->time_start;
      printf("%ldms     |%d is puting back fork\n", time, philo->id + 1);
    }
    pthread_mutex_unlock(&d->mutex_print);
    return (SUCCESS);
}

int    is_sleeping(t_data *d, t_philo *philo)
{
    pthread_mutex_lock(&d->mutex_print);
    if (d->philo_died == NO)
    {
      time = get_time() - d->time_start;
      printf("%ldms     |%d is sleeping\n", time, philo->id + 1);
    }
    pthread_mutex_unlock(&d->mutex_print);
    ft_sleep(d->eat, d);
    return (SUCCESS);
}

void    is_thinking(t_philo *philo)
{
    (void)philo;
    printf("im thinking\n");
}
