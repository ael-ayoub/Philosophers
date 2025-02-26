/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:34:19 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/26 14:46:50 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <limits.h>
# include <math.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct timeval	t_time;

typedef struct s_data
{
	time_t				sleep;
	time_t				die;
	time_t				eat;
	int					nbr_p;
	int					alive;
	int					option_arg;
	pthread_mutex_t		write;
	pthread_mutex_t		*forks;
}						t_data;

typedef struct s_philos
{
	int					id_philo;
	int					number_eat;
	pthread_t			id_thread;
	pthread_mutex_t		*right;
	pthread_mutex_t		*left;
	t_data				*data;
	t_time				last_meal_time;
}						t_philos;

int						init_data_1(t_data *data, char **av);
int						init_data_2(t_data *data, char **av);

int						init_time_1(char **av, t_data *data);
int						init_time_2(char **av, t_data *data);
time_t					set_time(t_time start, t_time end);

t_philos				*init_threads(t_data *data);

void					*simulation_1(void *arg);
void					*simulation_2(void *arg);
void					cleanup(t_data *data, t_philos *philos);
int						create_threads(t_data *data, t_philos *philos);
void					join_threads(t_data *data, t_philos *philos);

int						died(t_philos *philo, t_time start, t_time end);
void					taken_fork(t_philos *philo, t_time start);
void					eating(t_philos *philo, t_time start, t_time end);
void					sleeping(t_philos *philo, t_time start, t_time end);
void					thinking(t_philos *philo, t_time start, t_time end);
long					ft_atoi(char *str);
void					even_odd(t_time start, t_philos *philo);

#endif