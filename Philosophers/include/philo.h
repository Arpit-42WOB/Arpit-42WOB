/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:38:55 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/06 22:21:51 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define ERR_MSG "Error: Invalid arguments\nInput is Required in below \
mentioned order (all Values must be Positive Integer Numbers):\n\
number_of_philosophers, time_to_die, time_to_eat, \
time_to_sleep, [number_of_times_each_philosopher_must_eat]\n\
-> Number_of_philosophers: Number of philosophers and forks\n\
-> Time_to_die: Time in milliseconds after which a philosopher dies if not \
eating\n\
-> Time_to_eat: Time in milliseconds taken by a philosopher to eat\n\
-> Time_to_sleep: Time in milliseconds taken by a philosopher to sleep\n\
-> Number_of_times_each_philosopher_must_eat (Optional argument): \
Number of times each philosopher must eat before exiting the simulation\n"

# define DIED "died"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define FORK "has taken a fork"

typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*mutex_lock;
	int				num_of_philos;
	int				id;
	int				left_fork;
	int				right_fork;
	int				num_of_meals;
	int				*eating_count;
	int				*is_dead;
	int				num_of_times_each_philo_must_eat;
	uint64_t		start_time;
	uint64_t		sleep_time;
	uint64_t		eat_time;
	uint64_t		die_time;
	uint64_t		last_eating_time;
}	t_philo;

//check_input.c

int			ft_isdigit(int c);
int			ft_atoi(char *str);
int			is_argument_valid(char *str);
int			validate_param(int argc, char **argv);
int			check_input(int argc, char **argv, t_philo **philo);

//init.c
int			init_mutex(t_philo *philo);
void		init_timings(char **argv, t_philo *philo, uint64_t start_time);
void		init_philo_values(int id, t_philo *philo);
int			alloc_memory(t_philo *philo);
int			init_philos(int argc, char **argv, \
					t_philo *philo, uint64_t start_time);

//main.c
int			is_philo_dead(t_philo *philo);
int			philo_finished_eating(t_philo *philo);
void		monitor(t_philo *philo);
int			init_process(int argc, char **argv, t_philo **philo);

//threads.c
void		print_msg(char *msg, t_philo *philo);
void		philo_is_eating(t_philo *philo);
void		philo_at_dining_table(t_philo *philo);
void		*routine(void *data);
int			thread_init(t_philo *philo);

//time_and_exit.c
void		ft_usleep(useconds_t time);
u_int64_t	ft_get_time(void);
void		join_all_threads(t_philo *philo);
void		destroy_mutex(t_philo *philo);
void		ft_exit(t_philo *philo, int exit_code);

#endif
