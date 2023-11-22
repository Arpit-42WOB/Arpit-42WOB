/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:21:33 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/27 13:21:35 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../include/minishell.h"

int	word_modif_two(t_token **stc, char *duplica, t_quote quote, t_quote prec)
{
	char	*s1;
	int		cur;
	char	*str;

	if (init_str(&str, duplica, &cur, &s1) == NULL)
		return (50);
	while (str[cur])
	{
		quote = update_quote_status(str[cur], quote);
		if (prec != quote)
			prec = update_quote_success(*stc, &cur, quote, &s1);
		else
		{
			if (quote == SINGLE)
				s1 = word_will_single(str, &cur, s1);
			else if (quote == DOUBLE)
				s1 = word_will_double(str, &cur, s1);
			else if (quote == NONE)
				s1 = word_will_unquote(stc, str, &cur, s1);
		}
		if (s1 == NULL)
			return (free_str_ret_malloc_error(str));
	}
	return (end_modif_two(str, stc, s1));
}

int	word_modif(t_token **stc, char *str, t_e_token token)
{
	t_quote	quote;
	t_quote	prec;

	quote = NONE;
	prec = NONE;
	if (token == LIMITOR)
		return (limitor(*stc, str));
	return (word_modif_two(stc, str, quote, prec));
}

int	edit_type(t_command_line **block, int limitor)
{
	t_command_line	*temp;
	t_token			*token;

	temp = *block;
	while (temp)
	{
		token = temp->first_token;
		while (token)
		{
			if (token->type == HERE_DOC)
				limitor = 1;
			else if (limitor == 1 && token->str && token->str[0] != '\0')
			{
				if (is_type_file(token->type) == 1)
					return (ret_file_without_obj(token->type));
				token->type = LIMITOR;
				limitor = 0;
			}
			token = token->next;
		}
		if (limitor == 1)
			return (ret_file_without_obj(NON));
		temp = temp->next;
	}
	return (0);
}

int	check_open_fil(t_command_line **block)
{
	t_command_line	*temp;
	t_token			*token;
	int				file;
	t_e_token		type;

	temp = *block;
	file = 0;
	while (temp)
	{
		token = temp->first_token;
		while (token)
		{
			if (is_type_file(token->type) == 1 && file == 1)
				return (ret_file_without_obj(token->type));
			else if (is_type_file(token->type) == 1)
				type = cp_type_change_file(token->type, &file);
			else if (file == 1 && token->str && (token->str[0] != '\0'))
				token->type = change_type_file(type, &file);
			token = token->next;
		}
		if (file == 1)
			return (ret_error_file_without_file(temp->next));
		temp = temp->next;
	}
	return (0);
}

int	expend_words(t_command_line **block, int res)
{
	t_command_line	*temp;
	t_token			*token;

	temp = *block;
	if (edit_type(block, 0) != 0 || check_open_fil(block) != 0)
		return (12);
	while (temp)
	{
		token = temp->first_token;
		while (token)
		{
			if (token->str && token->str[0] != '\0')
			{
				res = word_modif(&token, token->str, token->type);
				if (token->str && token->str[0] == '\0' && !token->empty_quote)
					token->type = NON;
				if (res != 0)
					return (50);
			}
			token = token->next;
		}
		temp = temp->next;
	}
	return (0);
}
