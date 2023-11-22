/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:36:54 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/27 10:41:53 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

int	g_exit_status;

int	pars(char *str, t_command_line **cmd_line)
{
	int	res;

	res = unclose_quote(str);
	if (res > 0)
	{
		ft_putstr_fd("minishell: missing quote\n", 2);
		free_all(cmd_line);
	}
	else
	{
		if (get_cmd_line(str, cmd_line) > 0)
			return (free_str_all_ret_malloc_error(cmd_line, str));
		if (split_all_cmdl_string_to_token(cmd_line) > 0)
			return (free_str_all_ret_malloc_error(cmd_line, str));
		res = expend_words(cmd_line, 0);
		if (res != 0)
		{
			if (res == 50)
				return (free_str_ret_malloc_error(str));
		}
		if (organise_arg(cmd_line) != 0)
			return (free_str_all_ret_malloc_error(cmd_line, str));
	}
	return (res);
}

void	signal_cmd(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_status = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (sig == SIGTSTP || sig == SIGQUIT)
	{
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			return (print_error_msg_pipe(str));
		else if (str[i] == '&')
			return (print_error_msg_ampresent(str));
		else if (str[i] == ')')
			return (print_error_msg_closing_brace(str));
		else if (str[i] == ']')
			return (print_error_msg_closing_square(str));
		else if (str[i] == '}')
			return (print_error_msg_closing_curly(str));
		i++;
	}
	return (0);
}

void	go_to_exec(t_command_line **cmd_line, char *str)
{
	int	res;

	res = pars(str, cmd_line);
	if (res == 50)
	{
		free_all_env_str_ret_malloc_error(cmd_line, str);
		exit (1);
	}
	if (res == 0)
	{
		if (str != NULL && *cmd_line != NULL)
		{
			res = ft_exec(cmd_line);
			if (res != 0)
			{
				free_all_error(cmd_line, str, res);
				exit (1);
			}
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	char			*str;
	t_command_line	*cmd_line;

	cmd_line = NULL;
	g_exit_status = 0;
	ft_init_t_env(env);
	handle_signals();
	if (!argc && !argv)
		return (0);
	while (1)
	{
		str = readline("minishell : ");
		add_history(str);
		handle_signals();
		if (str == NULL)
			return (print_exit_free_env_all(&cmd_line));
		if (check_str(str) != 0)
			error_str();
		else
			go_to_exec(&cmd_line, str);
		free_end(&cmd_line, str);
	}
	return (g_exit_status);
}
