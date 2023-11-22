/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:56:50 by amehrotr          #+#    #+#             */
/*   Updated: 2023/07/07 12:06:45 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(a);
			(*cost)++;
		}
	}
}

void	do_rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(b);
			(*cost)++;
		}
	}
}

int	find_highest_index(t_stack *stack)
{
	int	index;

	index = stack -> index;
	while (stack)
	{
		if (stack -> index > index)
			index = stack -> index;
		stack = stack -> next;
	}
	return (index);
}

void	tiny_sort(t_stack **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)-> index == highest)
		do_ra(stack);
	else if ((*stack)-> next -> index == highest)
		do_rra(stack);
	if ((*stack)-> index > (*stack)-> next -> index)
		do_sa(stack);
}
