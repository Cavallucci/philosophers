#ifndef PHILO_H
# define PHILO_H

# include <time.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

# define ERROR 1
# define SUCCESS 0

typedef struct          s_data
{
    int             test;
    int			    nb_philo;
    pthread_mutex_t *forks;
    pthread_mutex_t eat;
    pthread_mutex_t sleep;
    pthread_mutex_t think;
    pthread_mutex_t die;
    t_philo          *philo;
}                       t_data;

typedef	struct			s_philo
{
    int             id;
    int             right_fork;
    int             left_fork;
    int             meal_eaten;
	pthread_t	    thread;
//    t_var           *var;
}						t_philo;

/*--------------philo.c--------------*/
void    init_data(t_data *d, char **argv);
int		main(int argc, char **argv);

/*--------------check.c--------*/
int     check_arg(int argc, char **argv);

/*--------------philo_libft.c--------*/
int		ft_atoi(const char *str);
int     ft_isnumeric(int c);
void    ft_bzero(void *s, size_t n);
void    *ft_calloc(size_t count, size_t size);

#endif
