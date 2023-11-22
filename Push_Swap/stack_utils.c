/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:05:12 by amehrotr          #+#    #+#             */
/*   Updated: 2023/07/07 12:06:33 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr -> value == INT_MIN && ptr -> index == 0)
				ptr -> index = 1;
			if (ptr -> value > value && ptr -> index == 0)
			{
				value = ptr -> value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr -> next;
		}
		if (highest != NULL)
			highest -> index = stack_size;
	}
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack -> next;
		size++;
	}
	return (size);
}

void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b -> index, INT_MAX, target_pos);
		tmp_b -> target_pos = target_pos;
		tmp_b = tmp_b -> next;
	}
}

t_stack	*get_stack_before_bottom(t_stack *stack)
{
	while (stack && stack -> next && stack -> next ->next != NULL)
		stack = stack -> next;
	return (stack);
}

void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp -> pos = i;
		tmp = tmp -> next;
		i++;
	}
}
