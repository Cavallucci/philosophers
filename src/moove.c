/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:41:15 by lcavallu          #+#    #+#             */
/*   Updated: 2022/01/20 20:40:43 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    take_fork(t_data *d, t_philo *philo)
{
    if (pthread_mutex_lock(&d->forks[philo->left_fork]))
        return (ERROR);
    if (pthread_mutex_lock(&d->forks[philo->right_fork]))
        return (ERROR);
    printf("im taking a fork\n");
    return (SUCCESS);
}

void    is_eating(t_data *d, t_philo *philo)
{
    (void)d;
    (void)philo;
    printf("im eating\n");
}

int    put_down_forks(t_data *d, t_philo *philo)
{
    if (pthread_mutex_unlock(&d->forks[philo->right_fork]))
        return (ERROR);
    if (pthread_mutex_unlock(&d->forks[philo->right_fork]))
        return (ERROR);
    printf("im putting back my forks\n");
    return (SUCCESS);
}

void    is_sleeping(t_data *d, t_philo *philo)
{
    (void)d;
    (void)philo;
    printf("im sleeping\n");
}

void    is_thinking(t_philo *philo)
{
    (void)philo;
    printf("im thinking\n");
}
