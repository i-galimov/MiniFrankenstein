/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtire <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:45:29 by rtire             #+#    #+#             */
/*   Updated: 2022/06/05 01:45:34 by rtire            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_heredoc(t_lst *o)
{
	if (g_o.fd_in > 0)
	{
		free(o->next->str);
		o->next->str = NULL;
	}
	else
		ft_free_all();
}

void	ft_heredoc(t_lst *o)
{
	char	*tmp;
	char	*res;

	res = NULL;
	while (1)
	{
		tmp = readline("> ");
		if (ft_strcmp(tmp, o->str) == 0)
			break ;
		if (!tmp)
			return (free(res));
		if (ft_strlen(res))
			res = ft_sjoin(res, "\n", 1, 0);
		res = ft_sjoin(res, tmp, 1, 1);
	}
	res = ft_sjoin(res, "\n", 1, 0);
	pipe(g_o.pipe);
	write(g_o.pipe[1], res, ft_strlen(res));
	g_o.fd_in = g_o.pipe[0];
	close(g_o.pipe[1]);
	free(tmp);
	free(res);
	free(o->str);
	o->str = NULL;
}

void	ft_check_put_list(int flag)
{
	g_o.count_final = 0;
	if (flag)
	{
		while (g_o.args)
		{
			if (ft_strlen(g_o.args->str))
				g_o.final_args[g_o.count_final++] = ft_strdup(g_o.args->str);
			free(g_o.args->str);
			free(g_o.args);
			g_o.args = g_o.args->next;
		}
	}
	else
	{
		while (g_o.args && !g_o.args->pipe_flag)
		{
			if (ft_strlen(g_o.args->str))
				g_o.final_args[g_o.count_final++] = ft_strdup(g_o.args->str);
			free(g_o.args->str);
			free(g_o.args);
			g_o.args = g_o.args->next;
		}
	}
}

void	ft_put_list(int flag)
{
	t_lst	*tmp;

	g_o.count_final = 0;
	tmp = g_o.args;
	if (flag)
	{
		while (tmp)
		{
			if (ft_strlen(tmp->str) != 0)
				g_o.count_final++;
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp && tmp->pipe_flag != 1)
		{
			if (ft_strlen(tmp->str) != 0)
				g_o.count_final++;
			tmp = tmp->next;
		}
	}
	g_o.final_args = malloc(sizeof(char *) * g_o.count_final + 1);
	ft_check_put_list(flag);
	g_o.final_args[g_o.count_final] = NULL;
}

void	ft_put_final_args(void)
{
	if (!g_o.final)
		g_o.final = ft_put_lst_new();
	else
		ft_lstadd_back(&g_o.final, ft_put_lst_new());
}
