#include "philo.h"

void    take_fork(t_data *d, t_philo *philo)
{
    (void)d;
    (void)philo;
    printf("im taking a fork\n");
}

void    is_eating(t_data *d, t_philo *philo)
{
    (void)d;
    (void)philo;
    printf("im eating\n");
}

void    put_down_forks(t_data *d, t_philo *philo)
{
    (void)d;
    (void)philo;
    printf("im putting back my forks\n");
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
