/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:06:31 by amehrotr          #+#    #+#             */
/*   Updated: 2023/07/07 12:06:12 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	do_pa(a, b);
}

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp -> pos;
	while (tmp)
	{
		if (tmp -> index < lowest_index)
		{
			lowest_index = tmp -> index;
			lowest_pos = tmp -> pos;
		}
		tmp = tmp -> next;
	}
	return (lowest_pos);
}

void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp -> cost_a) + ft_abs(tmp -> cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(tmp -> cost_b) + ft_abs(tmp -> cost_a);
			cost_a = tmp -> cost_a;
			cost_b = tmp -> cost_b;
		}
		tmp = tmp -> next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b -> cost_b = tmp_b -> pos;
		if (tmp_b -> pos > size_b / 2)
			tmp_b -> cost_b = (size_b - tmp_b -> pos) * -1;
		tmp_b -> cost_a = tmp_b -> target_pos;
		if (tmp_b -> target_pos > size_a / 2)
			tmp_b -> cost_a = (size_a - tmp_b -> target_pos) * -1;
		tmp_b = tmp_b -> next;
	}
}
