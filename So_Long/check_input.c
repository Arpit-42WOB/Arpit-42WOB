/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:31:21 by amehrotr          #+#    #+#             */
/*   Updated: 2023/07/07 13:42:18 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_duplicates(t_stack *t)
{
	int		temp;
	t_stack	*u;

	temp = t->value;
	t = t->next;
	while (t)
	{
		u = t;
		while (u)
		{
			if (u -> value == temp)
				exit_with_error(&t, NULL);
			u = u->next;
		}
		temp = t->value;
		t = t->next;
	}
}

int	is_number(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '+' || av[i] == '-' || av[i] == ' ') && av[i + 1] != '\0')
		i++;
	while (av[i] && (is_digit(av[i]) || av[i] == ' '))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

int	is_sorted(t_stack *stack)
{
	while (stack -> next != NULL)
	{
		if (stack -> value > stack -> next -> value)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

void	exit_with_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}
