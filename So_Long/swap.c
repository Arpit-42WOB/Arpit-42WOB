/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:21:49 by amehrotr          #+#    #+#             */
/*   Updated: 2023/07/07 12:06:41 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack -> next == NULL)
		return ;
	tmp = stack -> value;
	stack -> value = stack -> next -> value;
	stack -> next -> value = tmp;
	tmp = stack -> index;
	stack -> index = stack -> next -> index;
	stack -> next -> index = tmp;
}

void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr ("sa\n");
}

void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

void	do_ss(t_stack **stack_a, t_stack **stack_b, int i)
{
	swap(*stack_a);
	swap(*stack_b);
	if (i == 1)
		ft_putstr("ss\n");
}
