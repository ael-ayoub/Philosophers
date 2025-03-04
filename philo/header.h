/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:34:19 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/03/03 02:24:06 by ael-aiss         ###   ########.fr       */
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
	int					number;
	int					alive;
	t_time				start;
	int					option_arg;
	int					count;
	pthread_mutex_t		*write;
	pthread_mutex_t		*forks;
}						t_data;

typedef struct s_thread
{
	int					index;
	int					number_eat;
	pthread_t			id;
	pthread_mutex_t		*right;
	pthread_mutex_t		*left;
	t_data				*data;
	t_time				last_meal_time;
}						t_thread;

typedef struct s_monitor
{
	pthread_t			id_monitor;
	t_thread			*thread;
}						t_monitor;

int						init_data_1(t_data *data, char **av);
int						init_data_2(t_data *data, char **av);

t_monitor				*init_monitor(t_thread *philo);
void					monitor_function(t_monitor *monitor);

int						init_time_1(char **av, t_data *data);
int						init_time_2(char **av, t_data *data);
time_t					set_time(t_time start, t_time end);

t_thread				*init_threads(t_data *data);

void					*simulation_1(t_thread *philo);
void					*simulation_2(t_thread *philo);
void					simulation(t_thread *philo);
void					cleanup(t_data *data, t_thread *thread,
							t_monitor *monitor);
int						create_threads(t_data *data, t_thread *thread);
void					join_threads(t_data *data, t_thread *thread,
							t_monitor *monitor);

int						died(t_thread *philo);
void					taken_fork(t_thread *philo);
void					eating(t_thread *philo);
void					sleeping_thinking(t_thread *philo);
long					ft_atoi(char *str);
void					print_action(t_thread *philo, char *msg);

void					even_behavior(t_thread *philo);
void					odd_behavior(t_thread *philo);

void					one_philo(t_thread *philo);

#endif