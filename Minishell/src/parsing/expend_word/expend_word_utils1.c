/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_word_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:20:46 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:20:49 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/minishell.h"

extern int	g_exit_status;

int	ret_error_file_without_file(t_command_line *temp)
{
	ft_putstr_fd("minishell: syntax error near unexpected token", 2);
	g_exit_status = 258;
	if (temp)
		ft_putstr_fd(" '|'\n", 2);
	else
		ft_putstr_fd(" 'newline'\n", 2);
	return (12);
}

t_e_token	change_type_file(t_e_token type, int *file)
{
	*file = 0;
	if (type == OPEN_FILE)
		return (FILE_IN);
	else if (type == CREATE_FILE)
		return (FILE_OUT);
	else if (type == WRITE_FILE)
		return (FILE_OUT_OVER);
	else if (type == HERE_DOC)
		return (LIMITOR);
	return (NON);
}
