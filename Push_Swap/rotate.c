/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:23:06 by amehrotr          #+#    #+#             */
/*   Updated: 2023/09/26 14:57:48 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (get_stack_size(*stack) < 1)
		return ;
	tmp = *stack;
	*stack = (*stack)-> next;
	tail = get_stack_bottom(*stack);
	tmp -> next = NULL;
	tail -> next = tmp;
}

void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
	get_stack_size(*stack_a);
}

void	do_rb(t_stack **stack_b)
{
	if (get_stack_size(*stack_b) > 1)
		rotate(stack_b);
	ft_putstr("rb\n");
}

void	do_rr(t_stack **a, t_stack **b, int i)
{
	rotate(a);
	if (get_stack_size(*b) > 1)
		rotate(b);
	if (i == 1)
		ft_putstr("rr\n");
}

void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b, 1);
	}
}
