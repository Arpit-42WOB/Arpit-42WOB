/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpit <arpit@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 23:46:55 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/19 11:59:46 by arpit            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

extern int	g_exit_status;

int	ft_print_error(char *str1, char *str2)
{
	char	*ret;

	g_exit_status = 1;
	ret = ft_joinstr(str1, str2);
	if (ret == NULL)
		return (50);
	perror(ret);
	free(ret);
	return (0);
}
