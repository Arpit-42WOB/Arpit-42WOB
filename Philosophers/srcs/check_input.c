/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:33:58 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/06 22:22:05 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	if (is_argument_valid(str) != 0)
		return (-1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			return (-1);
	while (str[i] && ft_isdigit(str[i]) == 1)
		nbr = nbr * 10 + (str[i++] - '0');
	if (nbr > 2147483647)
		return (-1);
	return (nbr);
}

int	is_argument_valid(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	validate_param(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (-1);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 \
		|| ft_atoi(argv[4]) < 0 || (argc == 6 && ft_atoi(argv[5]) <= 0))
		return (-1);
	return (0);
}

int	check_input(int argc, char **argv, t_philo **philo)
{
	uint64_t	start_time;

	if (validate_param(argc, argv) == -1)
		return (-1);
	*philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!*philo)
		return (-1);
	start_time = ft_get_time();
	if (init_philos(argc, argv, *philo, start_time) == -1)
	{
		ft_exit(*philo, 1);
		return (-1);
	}
	if (init_mutex(*philo) == -1)
	{
		ft_exit(*philo, 2);
		return (-1);
	}
	return (0);
}
