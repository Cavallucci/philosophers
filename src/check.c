/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:41:15 by lcavallu          #+#    #+#             */
/*   Updated: 2022/01/25 16:09:08 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_arg(int argc, char **argv)
{
    int i;

    i = 1;
    if ((argc != 5 && argc != 6) || ft_atoi(argv[1]) == 0)
    {
        printf("error argument\n");
        return (ERROR);
    }
    while (argv[i])
    {
        if (ft_isnumeric(argv[i]) == ERROR || ft_atoi(argv[i]) == -1)
        {
            printf("error argument not valid\n");
            return (ERROR);
        }
        i++;
    }
    return (SUCCESS);
}

int init_data(t_data *d, char **argv)
{
    d->test = 0;
    d->nb_philo = ft_atoi(argv[1]);
    d->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), d->nb_philo);
    if (!d->forks)
        return (ERROR);
    d->eat = ft_atoi(argv[3]);
    d->sleep = ft_atoi(argv[4]);
    d->think = 0;
    d->die = ft_atoi(argv[2]);
    d->max_eat = -1;
    d->philo_died = NO;
    if (argv[5])
        d->max_eat = ft_atoi(argv[5]);
    if (init_philo(d) == ERROR)
    {
        printf("error init philo\n");
        return (ERROR);
    }
    d->time_start = get_time();
    return (SUCCESS);
}

int init_philo(t_data *d)
{
    t_philo *philo;
    int     i;

    i = 0;
    philo = (t_philo *)ft_calloc(sizeof(t_philo), d->nb_philo);
    if (!philo)
        return (ERROR);
    while (i < d->nb_philo)
    {
        philo[i].id = i;
        philo[i].right_fork = i;
        philo[i].left_fork = (i + 1) % d->nb_philo;
        philo[i].meal_eaten = 0;
        philo[i].data = d;
        philo[i].last_meal = -1;
        i++;
    }
    d->philo = philo;
    return (SUCCESS);
}

int init_mutex(t_data *d)
{
    int i;

    i = 0;
    if (pthread_mutex_init(&d->mutex_die, NULL) != 0 || pthread_mutex_init(&d->mutex_print, NULL) != 0 || pthread_mutex_init(&d->mutex_max_eat, NULL) != 0)
        return (ERROR);
    while (i < d->nb_philo)
    {
        if (pthread_mutex_init(&d->forks[i], NULL) != 0)
            return (ERROR);
        i++;
    }
    return (SUCCESS);
}
