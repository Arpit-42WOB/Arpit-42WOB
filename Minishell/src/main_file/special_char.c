/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:40:21 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/24 12:54:16 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

int	print_error_msg_pipe(char *str)
{
	int	i;
	int	dif;

	i = 0;
	dif = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && str[i] != '|'))
			dif = 1;
		if (str[i] == '|')
		{
			if (dif == 0)
			{
				if (ft_strnstr(str, "||", ft_strlen(str)) != NULL)
					ft_putstr_fd("minishell: \
syntax error near unexpected token '||' \n", 2);
				else if (ft_strnstr(str, "|", ft_strlen(str)) != NULL)
					ft_putstr_fd("minishell: \
syntax error near unexpected token '|' \n", 2);
				return (1);
			}
			dif = 0;
		}
		i++;
	}
	return (0);
}

int	print_error_msg_ampresent(char *str)
{
	int	i;
	int	dif;

	i = 0;
	dif = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && str[i] != '&'))
			dif = 1;
		if (str[i] == '&')
		{
			if (dif == 0)
			{
				if (ft_strnstr(str, "&&", ft_strlen(str)) != NULL)
					ft_putstr_fd("minishell: \
syntax error near unexpected token '&&' \n", 2);
				else if (ft_strnstr(str, "&", ft_strlen(str)) != NULL)
					ft_putstr_fd("minishell: \
syntax error near unexpected token '&' \n", 2);
				return (1);
			}
			dif = 0;
		}
		i++;
	}
	return (0);
}

int	print_error_msg_closing_brace(char *str)
{
	int	i;
	int	dif;

	i = 0;
	dif = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && str[i] != ')'))
			dif = 1;
		if (str[i] == ')')
		{
			if (dif == 0)
			{
				ft_putstr_fd("minishell: \
syntax error near unexpected token ')' \n", 2);
				return (1);
			}
			dif = 0;
		}
		i++;
	}
	return (0);
}

int	print_error_msg_closing_square(char *str)
{
	if (ft_strcmp(str, "]]"))
	{
		ft_putstr_fd("minishell: \
syntax error near unexpected token ']]' \n", 2);
		return (1);
	}
	return (0);
}

int	print_error_msg_closing_curly(char *str)
{
	if (ft_strcmp(str, "}"))
	{
		ft_putstr_fd("minishell: \
syntax error near unexpected token '}' \n", 2);
		return (1);
	}
	return (0);
}
