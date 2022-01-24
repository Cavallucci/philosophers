/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:41:15 by lcavallu          #+#    #+#             */
/*   Updated: 2022/01/24 19:12:27 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long    get_time(void)
{
    struct timeval  time;
    unsigned long            timestamp;

    gettimeofday(&time, NULL);
    timestamp = time.tv_sec * 1000 + time.tv_usec / 1000;
    return (timestamp);
}

void*	routine(void* philosopher)
{
    t_philo *philo;
    _Bool     is_max_present;

    philo = philosopher;
    if (philo->id % 2 != 0)
        usleep(1000);
    is_max_present = YES;
    if (philo->data->max_eat == -1)
        is_max_present = NO;
    while ((is_max_present == YES && philo->meal_eaten < philo->data->max_eat) || is_max_present == NO)
    {
        if (philo_dead(philo->data) == YES)
            break;
        take_fork(philo->data, philo);
        is_eating(philo->data, philo);
        put_down_forks(philo->data, philo);
        if (philo_dead(philo->data) == NO)
           is_sleeping(philo->data, philo);
        if (philo_dead(philo->data) == NO)
            is_thinking(philo->data, philo);
    }
    return (philo);
}

int	main (int argc, char **argv)
{
    t_data	d[1];
//modifier atoi avec le int max
    if (check_arg(argc, argv) == ERROR || init_data(d, argv) == ERROR || init_mutex(d) == ERROR)
        return (ERROR);
    if (create_thread(d->philo, d) == ERROR)
        return (ERROR);
    check_death(d, d->philo);
    if (join_thread(d->philo, d) == ERROR)
       return (ERROR);
}
