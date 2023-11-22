/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:35:12 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/06 22:24:57 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_usleep(useconds_t time)
{
	long long	now;
	long long	elapsed;

	now = ft_get_time();
	elapsed = ft_get_time();
	while (elapsed - now < time)
	{
		usleep(200);
		elapsed = ft_get_time();
	}
}

u_int64_t	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	join_all_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_of_philos)
	{
		pthread_join(philo[i].philo, NULL);
		i++;
	}
}

void	destroy_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(philo->mutex_lock);
	while (i < philo->num_of_philos)
	{
		pthread_mutex_destroy(&philo->fork_mutex[i]);
		i++;
	}
}

void	ft_exit(t_philo *philo, int exit_code)
{
	if (exit_code == 1)
		free(philo);
	else
	{
		destroy_mutex(philo);
		if (philo->fork_mutex)
			free(philo->fork_mutex);
		if (philo->mutex_lock)
			free(philo->mutex_lock);
		if (philo->is_dead)
			free(philo->is_dead);
		if (philo->eating_count)
			free(philo->eating_count);
		if (philo)
			free(philo);
	}
}
