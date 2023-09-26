/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:20:47 by amehrotr          #+#    #+#             */
/*   Updated: 2023/07/07 13:43:01 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)-> next;
	(*src)-> next = *dest;
	*dest = *src;
	*src = tmp;
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}

t_stack	*fill_stack_values(int ac, char **av, int i)
{
	t_stack		*stack_a;
	int			wc;
	char		**str;
	int			f;

	stack_a = NULL;
	f = 0;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			exit_with_error(&stack_a, NULL);
		str = ft_split(av[i], ' ');
		wc = count_words(av[i], ' ');
		push_stack(&stack_a, wc, str, f);
		f = 1;
		i++;
		ft_free_strmem(str);
	}
	return (stack_a);
}

void	push_stack(t_stack **stack_a, int wc, char **str, int f)
{
	int			j;
	long int	nb;

	j = 0;
	while (j < wc)
	{
		nb = ft_atoi(str[j]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_with_error(&(*stack_a), NULL);
		if (is_number(str[j]) == 0)
			exit_with_error(&(*stack_a), NULL);
		if (f == 0)
		{
			*stack_a = stack_new((int)nb);
			f = 1;
		}
		else
			stack_add_bottom(&(*stack_a), stack_new((int)nb));
		j++;
	}
}
