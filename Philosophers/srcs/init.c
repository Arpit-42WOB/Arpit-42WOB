/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:51:47 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/06 20:55:45 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(philo->mutex_lock, NULL) != 0)
		return (-1);
	while (i < philo->num_of_philos)
	{
		if (pthread_mutex_init(&philo->fork_mutex[i], NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}

void	init_timings(char **argv, t_philo *philo, uint64_t start_time)
{
	philo->start_time = start_time;
	philo->last_eating_time = start_time;
	philo->die_time = ft_atoi(argv[2]);
	philo->eat_time = ft_atoi(argv[3]);
	philo->sleep_time = ft_atoi(argv[4]);
}

void	init_philo_values(int id, t_philo *philo)
{
	philo->id = id + 1;
	philo->left_fork = id;
	philo->right_fork = (id + 1) % philo->num_of_philos;
	philo->num_of_meals = 0;
	philo->num_of_times_each_philo_must_eat = 0;
}

int	alloc_memory(t_philo *philo)
{
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*mutex_lock;
	int				*is_dead;
	int				*eating_count;

	fork_mutex = malloc(sizeof(pthread_mutex_t) * philo->num_of_philos);
	mutex_lock = malloc(sizeof(pthread_mutex_t));
	is_dead = malloc(sizeof(int));
	eating_count = malloc(sizeof(int));
	if (!fork_mutex || !mutex_lock || !is_dead || !eating_count)
		return (-1);
	*is_dead = 0;
	*eating_count = 0;
	philo->fork_mutex = fork_mutex;
	philo->mutex_lock = mutex_lock;
	philo->is_dead = is_dead;
	philo->eating_count = eating_count;
	return (0);
}

int	init_philos(int argc, char **argv, t_philo *philo, uint64_t start_time)
{
	int	i;
	int	num_of_philos;

	i = 0;
	num_of_philos = ft_atoi(argv[1]);
	philo->num_of_philos = num_of_philos;
	if (alloc_memory(philo) == -1)
		return (-1);
	while (i < philo->num_of_philos)
	{
		philo[i].fork_mutex = philo[0].fork_mutex;
		philo[i].mutex_lock = philo[0].mutex_lock;
		philo[i].is_dead = philo[0].is_dead;
		philo[i].eating_count = philo[0].eating_count;
		philo[i].num_of_philos = num_of_philos;
		init_philo_values(i, &philo[i]);
		init_timings(argv, &philo[i], start_time);
		if (argc == 6)
			philo[i].num_of_times_each_philo_must_eat = ft_atoi(argv[5]);
		i++;
	}
	return (0);
}
