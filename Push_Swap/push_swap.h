/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:57:44 by amehrotr          #+#    #+#             */
/*   Updated: 2023/07/06 20:21:33 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				pos;
	int				index;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//check _input.c
int			input_is_not_ok(char **av);
void		ft_check_duplicates(t_stack *t);
int			is_number(char *av);
int			is_sorted(t_stack *stack);
void		exit_with_error(t_stack **stack_a, t_stack **stack_b);

//get_next_line.c
size_t		ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);
int			ft_clear_line(char *str);
char		*get_next_line(int fd);

//push_swap_bonus_utils.c
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		check_commands(t_stack **stack_a, t_stack **stack_b);
void		apply_commands(char *str, t_stack **stack_a, t_stack **stack_b);

//push_swap_utils.c
int			get_target(t_stack **a, int b_idx, int target_idx, int target_pos);
void		push_all_save_three(t_stack **stack_a, t_stack **stack_b);
void		sort(t_stack **stack_a, t_stack **stack_b);
void		push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);

//push.c
void		push(t_stack **src, t_stack **dest);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
t_stack		*fill_stack_values(int ac, char **av, int i);
void		push_stack(t_stack **stack_a, int wc, char **str, int f);

//rev_rotate.c
void		rev_rotate(t_stack **stack);
void		do_rev_rotate_both(t_stack **a, t_stack **b,
				int *cost_a, int *cost_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b, int i);

//rotate.c
void		rotate(t_stack **stack);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **a, t_stack **b, int i);
void		do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);

//sort_utils.c
void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
int			get_lowest_index_position(t_stack **stack);
void		shift_stack(t_stack **stack_a);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void		get_cost(t_stack **stack_a, t_stack **stack_b);

//split_utils.c
char		*ft_substr(char *s, unsigned int start, size_t len);
int			count_words(const char *str, char c);
void		*ft_free_strmem(char **split);
char		**ft_get_str(char **split, int index, char *s, char c);
char		**ft_split(char *s, char c);

//stack_utils.c
void		assign_index(t_stack *stack_a, int stack_size);
int			get_stack_size(t_stack *stack);
void		get_target_position(t_stack **a, t_stack **b);
t_stack		*get_stack_before_bottom(t_stack *stack);
void		get_position(t_stack **stack);

//stack.c
void		free_stack(t_stack **stack);
void		stack_add_bottom(t_stack **stack, t_stack *new);
t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*stack_new(int value);

//swap.c
void		swap(t_stack *stack);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b, int i);

//tiny_sort.c
void		do_rotate_a(t_stack **a, int *cost);
void		do_rotate_b(t_stack **b, int *cost);
int			find_highest_index(t_stack *stack);
void		tiny_sort(t_stack **stack);

//utils.c
int			ft_abs(int num);
long int	ft_atoi(char *av);
int			is_digit(char c);
void		ft_putstr(char *str);

#endif