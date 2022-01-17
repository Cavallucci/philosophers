#include "philo.h"

long    get_time(void)
{
    struct timeval  time;
    long            timestamp;

    gettimeofday(&time, NULL);
    timestamp = time.tv_sec * 1000 + time.tv_usec / 1000;
    return (timestamp);
}

void*	routine(void* data)
{
    t_data  *d;

    d = data;
	pthread_mutex_lock(&d->mutex);
    printf("i = %d\n", d->i);
    usleep(1000000);
    printf("index = %i\n", d->test);
    pthread_mutex_unlock(&d->mutex);
    return (d);
}

void    init_data(t_data *d, char **argv)
{
    int i;

    i = ft_atoi(argv[1]);
    while (i > 0)
    {
    	d->id = i;
        d->right_fork = i + 1;
        d->left_fork = i - 1;
        d->meal_eaten = 0;
        d->var->test = 0;
        d->var->nb_philo = ft_atoi(argv[1]);
        d->thread = malloc(sizeof(int) * d->var->nb_philo);
        d->var->forks = 0;
        d->var->eat = 0;
        d->var->sleep = 0;
        d->var->think = 0;
        d->var->die = 0;
    }
}

int	main (int argc, char **argv)
{
	t_data	d[1];
	int		i;

	if (check_arg(argc, argv) == ERROR)
        return (ERROR);
    if (init_data(d, argv) == ERROR)
        return (ERROR);
		init_data(d,argv);
		i = 0;
        pthread_mutex_init(&d->mutex, NULL);
		while (i < d->var->nb_philo)
		{
			if (pthread_create(&d->thread, NULL, &routine, d) != 0)
				perror("Failed to created thread");
			i++;
		}
		i = 0;
		while (i < d->nb_philo)
		{
			if (pthread_join(d->thread[i], NULL) != 0)
				perror("Failed to join thread");
			i++;
		}
		free(d->thread);
        pthread_mutex_destroy(&d->mutex);
	}
    printf("time 2 = %ld\n", get_time());
}
