/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:19:52 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:19:53 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

int	ft_is_builtin(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strcmp(str, "exit"))
		return (2);
	if (ft_strcmp(str, "echo"))
		return (1);
	else if (ft_strcmp(str, "cd"))
		return (1);
	else if (ft_strcmp(str, "pwd"))
		return (1);
	else if (ft_strcmp(str, "export"))
		return (1);
	else if (ft_strcmp(str, "unset"))
		return (1);
	else if (ft_strcmp(str, "env"))
		return (1);
	return (0);
}
