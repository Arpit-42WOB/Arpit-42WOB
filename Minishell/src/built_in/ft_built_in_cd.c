/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:19:39 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/20 00:19:07 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

extern int	g_exit_status;

int	ft_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_home(void)
{
	t_env	*cpy;
	int		len;

	len = ft_get_lenkey("HOME=");
	cpy = *get_address_env();
	while (cpy)
	{
		if (len == ft_get_lenkey(cpy->str)
			&& !ft_strncmp(cpy->str, "HOME", len))
		{
			if (ft_equal(cpy->str))
				return (cpy->str + len + 1);
			return (NULL);
		}
		cpy = cpy->next;
	}
	return (NULL);
}

int	ft_pwd(char *str)
{
	char	*oldpwd;
	char	*pwd;
	int		ret;

	ret = 0;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		free(pwd);
		return (50);
	}
	oldpwd = ft_joinstr(str, pwd);
	free(pwd);
	if (oldpwd == NULL)
	{
		free(oldpwd);
		return (50);
	}
	ret = ft_add_env(oldpwd);
	free(oldpwd);
	return (ret);
}

int	ft_built_in_cd(char **str)
{
	if (*(str + 1) == NULL || ft_strcmp(str[1], "~"))
	{
		*(str + 1) = ft_get_home();
		if (*(str + 1) == NULL)
		{
			printf("HOME not set\n");
			return (0);
		}
		if (str[1][0] == '\0')
			return (0);
	}
	if (ft_pwd("OLDPWD=") == 50)
		return (50);
	if (chdir(*(str + 1)) == -1)
		if (ft_print_error("minishell: cd: ", *(str + 1)) == 50)
			return (50);
	if (ft_pwd("PWD=") == 50)
		return (50);
	return (0);
}
