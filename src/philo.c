#include "philo.h"

long    get_time(void)
{
    struct timeval  time;
    long            timestamp;

    gettimeofday(&time, NULL);
    timestamp = time.tv_sec * 1000 + time.tv_usec / 1000;
    return (timestamp);
}

void*	routine(void* philosopher)
{
    t_philo *philo;
    int     dead;

    philo = philosopher;
    dead = NO;
    while (dead == NO && philo->data->nb_philo > 1 && philo->meal_eaten < philo->data->max_eat)
    {
        if (philo_dead(philo->data, &dead) == YES)
            break;
        take_fork(philo->data, philo);
        is_eating(philo->data, philo);
        put_down_forks(philo->data, philo);
        if (philo_dead(philo->data, &dead) == NO)
           is_sleeping(philo->data, philo);
        if (philo_dead(philo->data, &dead) == NO)
            is_thinking(philo);
        if (philo_dead(philo->data, &dead) == YES)
            break;
    }
    return (philo);
}

int	main (int argc, char **argv)
{
    t_data	d[1];

    if (check_arg(argc, argv) == ERROR || init_data(d, argv) == ERROR || init_mutex(d) == ERROR || gettimeofday(&d->time_start, NULL) == -1)
        return (ERROR);
    if (create_thread(d->philo, d) == ERROR)
        return (ERROR);
    
}
