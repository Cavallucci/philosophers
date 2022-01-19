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

int philo_dead(t_data *d, int *dead)
{
    pthread_mutex_lock(&d->mutex_die);
    *dead = d->philo_died;
    pthread_mutex_unlock(&d->mutex_die);
    if (*dead == YES)
        return (YES);
    return (NO);
}
