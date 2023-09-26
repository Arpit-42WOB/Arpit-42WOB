/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:41:34 by amehrotr          #+#    #+#             */
/*   Updated: 2023/09/26 14:39:22 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i < n)
		return (str1[i] - str2[i]);
	else
		return (0);
}

void	check_commands(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL || !(ft_strlen(str) == 3 || ft_strlen(str) == 4))
			break ;
		apply_commands(str, stack_a, stack_b);
		free(str);
	}
	if (is_sorted(*stack_a) && (get_stack_size(*stack_b) == 0))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

void	apply_commands(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(str, "sa", 2) == 0)
		swap(*stack_a);
	else if (ft_strncmp(str, "sb", 2) == 0)
		swap(*stack_b);
	else if (ft_strncmp(str, "ss", 2) == 0)
		do_ss(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "ra", 2) == 0)
		rotate(stack_a);
	else if (ft_strncmp(str, "rb", 2) == 0)
		rotate(stack_b);
	else if (ft_strncmp(str, "pa", 2) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(str, "pb", 2) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(str, "rra", 3) == 0)
		rev_rotate(stack_a);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		rev_rotate(stack_b);
	else if (ft_strncmp(str, "rrr", 3) == 0)
		do_rrr(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "rr", 2) == 0)
		do_rr(stack_a, stack_b, 0);
	else
		exit_with_error(stack_a, stack_b);
}
