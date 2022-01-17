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
    d->test = 0;
	d->nb_philo = ft_atoi(argv[1]);
	d->thread = malloc(sizeof(int) * d->nb_philo);
}

int	main (int argc, char **argv)
{
	t_data	d[1];
	int		i;

    printf("timestamp %ld\n", get_time());
	if (argc > 1)
	{
		init_data(d,argv);
        d->i = 0;
		i = 0;
        pthread_mutex_init(&d->mutex, NULL);
		while (d->i < d->nb_philo)
		{
			if (pthread_create(&d->thread[d->i], NULL, &routine, d) != 0)
				perror("Failed to created thread");
			d->i++;
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
