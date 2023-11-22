/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:02:56 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/16 14:07:07 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

int	free_in_builin(t_command_line **str, pid_t *id, int ret)
{
	free(id);
	free_all(str);
	ft_clean_env();
	exit(ret);
	return (ret);
}
