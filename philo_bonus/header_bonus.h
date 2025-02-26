/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-aiss <ael-aiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:58:01 by ael-aiss          #+#    #+#             */
/*   Updated: 2025/02/26 11:47:54 by ael-aiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct timeval	t_time;

typedef struct s_data
{
	int					nbr_p;
	int					option_arg;
	time_t				sleep;
	time_t				die;
	time_t				eat;
	sem_t				*write;
	sem_t				*forks;
	sem_t				*alive;
	sem_t				*count;
	sem_t				*mutex_fork;
}						t_data;

typedef struct s_philos
{
	int					id_philo;
	int					number_eat;
	pid_t				id_process;
	t_data				*data;
	t_time				last_meal_time;
}						t_philos;

long					ft_atoi(char *str);

time_t					set_time(t_time start, t_time end);
int						init_time_1(char **av, t_data *data);
int						init_time_2(char **av, t_data *data);

int						validate_args(int ac, char *av[], t_data *data);
void					kill_processes(t_philos *philo);
int						initialize_simulation(int ac, char *av[],
							t_philos **philos, t_data *data);

void					eating(t_philos *philo, t_time start);
void					sleeping(t_philos *philo, t_time start);
void					thinking(t_philos *philo, t_time start);

int						init_data(t_data *data, char **av, int ac);

void					cleanup(t_philos *philos, t_data *data);
void					cleanup_child(t_philos *philos, t_data *data);
t_philos				*init_process(t_data *data);

void					taken_fork_1(t_philos *philo, t_time start);
void					taken_fork_2(t_philos *philo, t_time start);

void					print_actions(t_philos *philo, t_time start);
void					simulation_1(t_philos *philo);
void					simulation_2(t_philos *philo);

void					one_philo_1(t_philos *philo, t_time start);
void					one_philo_2(t_philos *philo, t_time start);
#endif