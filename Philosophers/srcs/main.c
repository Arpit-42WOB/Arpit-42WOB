/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:38:52 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/06 22:58:09 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_philo_dead(t_philo *philo)
{
	uint64_t	curr_time;

	curr_time = ft_get_time();
	if (curr_time - philo->last_eating_time > philo->die_time)
	{
		printf("%llu %d %s\n", curr_time - philo->start_time, philo->id, DIED);
		*(philo->is_dead) += 1;
		return (1);
	}
	return (0);
}

int	philo_finished_eating(t_philo *philo)
{
	if (philo->num_of_times_each_philo_must_eat != 0 && \
		*(philo->eating_count) >= philo->num_of_philos)
		return (1);
	return (0);
}

void	monitor(t_philo *philo)
{
	int	i;
	int	is_dead;
	int	eating_count;

	is_dead = 0;
	eating_count = 0;
	while (1)
	{
		i = 0;
		while (i < philo->num_of_philos)
		{
			pthread_mutex_lock(philo[i].mutex_lock);
			is_dead = is_philo_dead(&philo[i]);
			eating_count = philo_finished_eating(&philo[i]);
			pthread_mutex_unlock(philo[i].mutex_lock);
			if (eating_count != 0 || is_dead != 0)
				return ;
			i++;
		}
	}	
}

int	init_process(int argc, char **argv, t_philo **philo)
{
	if (check_input(argc, argv, philo) == -1)
	{
		printf(ERR_MSG);
		return (1);
	}
	thread_init(*philo);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (init_process(argc, argv, &philo) != 0)
		return (1);
	monitor(philo);
	join_all_threads(philo);
	if (*(philo->eating_count) == philo->num_of_philos \
		&& *(philo->is_dead) == 0)
		printf("%d philosphers ate %d times & Process is Stopped\n", \
			philo->num_of_philos, philo->num_of_times_each_philo_must_eat);
	ft_exit(philo, 3);
	return (0);
}
