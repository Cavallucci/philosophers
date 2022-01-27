/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:41:15 by lcavallu          #+#    #+#             */
/*   Updated: 2022/01/26 19:46:59 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define YES 0
# define NO 1

typedef struct s_data
{
	int				test;
	int				nb_philo;
	unsigned long	eat;
	int				sleep;
	int				think;
	int				die;
	int				max_eat;
	int				philo_died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_die;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_max_eat;
	unsigned long	time_start;
	struct s_philo	*philo;
}				t_data;

typedef struct s_philo
{
	int				id;
	int				right_fork;
	int				left_fork;
	int				meal_eaten;
	unsigned long	last_meal;
	pthread_t		thread;
	t_data			*data;
}				t_philo;

/*--------------philo.c--------------*/
unsigned long	get_time(void);
void			*routine(void *data);
void			ft_free(t_data *d, t_philo *philo);
int				main(int argc, char **argv);

/*--------------check.c--------*/
int				check_arg(int argc, char **argv);
int				init_data(t_data *d, char **argv);
int				init_philo(t_data *d);
int				init_mutex(t_data *d);

/*--------------philo_libft.c--------*/
int				ft_atoi(const char *str);
int				ft_isnumeric(char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);

/*--------------thread.c--------*/
int				create_thread(t_philo *philo, t_data *d);
int				philo_dead(t_data *d);
int				join_thread(t_philo *philo, t_data *d);
int				check_death(t_data *d, t_philo *philo);
int				ft_sleep(int time_eat, t_data *d);

/*--------------moove.c--------*/
int				take_fork(t_data *d, t_philo *philo);
int				is_eating(t_data *d, t_philo *philo);
int				put_down_forks(t_data *d, t_philo *philo);
int				is_sleeping(t_data *d, t_philo *philo);
int				is_thinking(t_data *d, t_philo *philo);

#endif
