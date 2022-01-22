/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:41:15 by lcavallu          #+#    #+#             */
/*   Updated: 2022/01/22 18:39:28 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    create_thread(t_philo *philo, t_data *d)
{
    int i;

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

int philo_dead(t_data *d, _Bool *dead)
{
    if (pthread_mutex_lock(&d->mutex_die) != 0)
        return (ERROR);
    *(dead) = d->philo_died;
    if (pthread_mutex_unlock(&d->mutex_die) != 0)
        return (ERROR);
    if (*dead == YES)
        return (YES);
    return (NO);
}

int join_thread(t_philo *philo, t_data *d)
{
    int i;

    i = 0;
    while (i < d->nb_philo)
    {
        if (pthread_join(philo[i].thread, NULL) != 0)
            return (ERROR);
        i++;
    }
    return (SUCCESS);
}
