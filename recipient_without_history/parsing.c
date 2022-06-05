/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtire <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:29:43 by rtire             #+#    #+#             */
/*   Updated: 2022/06/05 01:29:45 by rtire            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_open_file(t_lst *o, int flag)
{
	if (flag == 1)
	{
		g_o.fd_in = open(o->str, O_RDONLY, O_CLOEXEC);
		if (g_o.fd_in == -1)
			return (1);
	}
	else if (flag == 2)
	{
		g_o.fd_out = open(o->str, O_WRONLY \
			| O_CLOEXEC | O_TRUNC | O_CREAT, 0644);
		if (g_o.fd_out == -1)
			return (1);
	}
	else if (flag == 3)
	{
		g_o.fd_out = open(o->str, O_WRONLY \
			| O_CLOEXEC | O_APPEND | O_CREAT, 0644);
		if (g_o.fd_out == -1)
			return (1);
	}
	free(o->str);
	o->str = NULL;
	return (0);
}

void	ft_parsing(void)
{
	int		j;
	t_lst	*tmp;

	tmp = g_o.args;
	while (tmp)
	{
		j = -1;
		while (tmp->str && tmp->str[++j])
		{
			if (tmp->str[j] == '\'')
				tmp->str = ft_parse_quotes(tmp, &j, '\'');
			else if (tmp->str[j] == '"')
				tmp->str = ft_parse_quotes(tmp, &j, '"');
			else if (tmp->str[j] == '$' \
				&& (ft_isalnum(tmp->str[j + 1]) || tmp->str[j + 1] == '?'))
				tmp->str = ft_parse_dollar(tmp->str, &j);
			else if (!tmp->flag_meta \
				&& (tmp->str[j] == '<' || tmp->str[j] == '>'))
				tmp->str = ft_redirects(tmp, &j);
			else if (!tmp->flag_meta && tmp->str[j] == '|')
				tmp->str = ft_parse_redirect(tmp, 2, 0);
		}
		tmp = tmp->next;
	}
	return ;
}
