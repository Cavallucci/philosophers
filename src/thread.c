/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:41:15 by lcavallu          #+#    #+#             */
/*   Updated: 2022/01/24 20:28:22 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    create_thread(t_philo *philo, t_data *d)
{
    int i;

    i = 0;

    while (i < d->nb_philo)
    {
        if (pthread_create(&(philo[i]).thread, NULL, &routine, &philo[i]) != 0)
            return (ERROR);
        i++;
    }
    return (SUCCESS);
}

int philo_dead(t_data *d)
{
    pthread_mutex_lock(&d->mutex_die);
    if (d->philo_died == YES)
    {
        d->philo_died  = YES;
        pthread_mutex_unlock(&d->mutex_die);
        return (YES);
    }
    else
    {
        d->philo_died  = NO;
        pthread_mutex_unlock(&d->mutex_die);
        return (NO);
    }
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

int check_death(t_data *d, t_philo *philo)
{
    unsigned long   time_now;
    int             i;

    i= 0;
    while (d->philo_died == NO)
    {
        time_now = philo[i].last_meal - get_time();
        if (time_now > d->eat)
        {
            d->philo_died = YES;
            printf("philo %i died at %ld\n", i + 1, time_now);
            return (YES);
        }
        if (i == d->nb_philo)
            i = 0;
        else
            i++;
        usleep(100);
    }
    return (NO);
}
