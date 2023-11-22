/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:04:09 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/06 23:00:12 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_msg(char *msg, t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_lock);
	if (*(philo->is_dead) == 0)
		printf("%llu %d %s\n", \
			ft_get_time() - philo->start_time, philo->id, msg);
	pthread_mutex_unlock(philo->mutex_lock);
}

void	philo_is_eating(t_philo *philo)
{
	print_msg(EATING, philo);
	pthread_mutex_lock(philo->mutex_lock);
	philo->last_eating_time = ft_get_time();
	pthread_mutex_unlock(philo->mutex_lock);
	ft_usleep(philo->eat_time);
	pthread_mutex_lock(philo->mutex_lock);
	philo->num_of_meals++;
	if (philo->num_of_times_each_philo_must_eat != 0 && \
		philo->num_of_meals == philo->num_of_times_each_philo_must_eat)
		*(philo->eating_count) += 1;
	pthread_mutex_unlock(philo->mutex_lock);
}

void	philo_at_dining_table(t_philo *philo)
{
	print_msg(THINKING, philo);
	pthread_mutex_lock(&philo->fork_mutex[philo->left_fork]);
	print_msg(FORK, philo);
	if (philo->num_of_philos == 1)
	{
		pthread_mutex_unlock(&philo->fork_mutex[philo->left_fork]);
		ft_usleep(philo->die_time + 1);
		return ;
	}
	pthread_mutex_lock(&philo->fork_mutex[philo->right_fork]);
	print_msg(FORK, philo);
	philo_is_eating(philo);
	pthread_mutex_unlock(&philo->fork_mutex[philo->left_fork]);
	pthread_mutex_unlock(&philo->fork_mutex[philo->right_fork]);
	print_msg(SLEEPING, philo);
	ft_usleep(philo->sleep_time);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		ft_usleep(10);
	while (1)
	{
		philo_at_dining_table(philo);
		pthread_mutex_lock(philo->mutex_lock);
		if (*(philo->eating_count) == philo->num_of_philos \
		|| *(philo->is_dead) > 0)
		{
			pthread_mutex_unlock(philo->mutex_lock);
			break ;
		}
		pthread_mutex_unlock(philo->mutex_lock);
	}
	return (NULL);
}

int	thread_init(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->num_of_philos)
	{
		if (pthread_create(&philo[i].philo, NULL, routine, &philo[i]) != 0)
			return (-1);
	}
	return (0);
}
