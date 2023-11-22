/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_word_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:21:48 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:21:49 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/minishell.h"

extern int	g_exit_status;

char	*init_str(char **str, char *duplica, int *cur, char **s1)
{
	*s1 = NULL;
	*cur = 0;
	*str = ft_strdup(duplica);
	free(duplica);
	if (*str == NULL)
		return (NULL);
	return (*str);
}

int	end_modif_two(char *str, t_token **stc, char *s1)
{
	free(str);
	(*stc)->str = s1;
	return (0);
}

int	is_type_file(t_e_token type)
{
	if (type == CREATE_FILE || type == WRITE_FILE
		|| type == OPEN_FILE || type == HERE_DOC)
		return (1);
	return (0);
}

int	ret_file_without_obj(t_e_token type)
{
	ft_putstr_fd("minishell: syntax error near unexpected token", 2);
	g_exit_status = 258;
	if (type == NON)
		ft_putstr_fd(" 'newline'\n", 2);
	else if (type == CREATE_FILE)
		ft_putstr_fd(" >\n", 2);
	else if (type == WRITE_FILE)
		ft_putstr_fd(" >>\n", 2);
	else if (type == OPEN_FILE)
		ft_putstr_fd(" <\n", 2);
	else if (type == HERE_DOC)
		ft_putstr_fd(" <<\n", 2);
	return (12);
}

t_e_token	cp_type_change_file(t_e_token type, int *file)
{
	*file = 1;
	return (type);
}
