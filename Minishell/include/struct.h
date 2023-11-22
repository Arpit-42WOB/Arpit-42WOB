/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:21:46 by ahsalam           #+#    #+#             */
/*   Updated: 2023/10/26 23:08:14 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum quote
{
	NONE,
	SINGLE,
	DOUBLE,
	BACKSLASH,
	END,
}			t_quote;

typedef enum mod
{
	GET,
	DELETE,
	FREE,
	ADD,
}			t_mode;

typedef enum token
{
	NON,
	ARG,
	BUILTIN,
	OPEN_FILE,
	HERE_DOC,
	LIMITOR,
	CREATE_FILE,
	WRITE_FILE,
	FILE_IN,
	FILE_OUT,
	FILE_OUT_OVER,
	ENDS,
}			t_e_token;

typedef struct s_exec
{
	char			**argv;
	int				fd_in;
	int				fd_out;
	struct s_exec	*next;
}			t_exec;

typedef struct s_token
{
	char				*str;
	t_e_token			type;
	bool				empty_quote;
	bool				expanded;
	struct s_token		*next;
}				t_token;

typedef struct s_command_line
{
	char					*string;
	t_token					*first_token;
	char					**envp;
	char					**argv;
	int						fd_in;
	int						fd_out;
	char					*name_file;
	struct s_command_line	*next;
}				t_command_line;

typedef struct s_env
{
	char			*str;
	int				declar;
	struct s_env	*next;
}			t_env;

#endif