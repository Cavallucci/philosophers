#include "philo.h"

int check_arg(int argc, char **argv)
{
    int i;

    i = 1;
//    if (argc != 4 || argc != 5)
    if (argc < 1 || argv[1] == 0)
        return (ERROR);
    while (argv[i])
    {
        if (is_numeric(argv[i] || ft_atoi(argv[i] == -1)
            return (ERROR);
    }
    return (SUCCESS);
}

int init_data(t_data *d, char **argv)
{
    d->test = 0;
    d->nb_philo = ft_atoi(argv[1]);
    d->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), var->number_of_forks);
    d->eat = ft_atoi(argv[3]);
    d->sleep = ft_atoi(argv[4]);
    d->think = 0;
    d->die = ft_atoi(argv[2]);

}
