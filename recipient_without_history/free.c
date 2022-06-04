/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtire <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:09:51 by rtire             #+#    #+#             */
/*   Updated: 2022/06/04 16:09:53 by rtire            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_struct(t_lst *s)
{
	int		i;
	t_lst	*tmp;

	i = -1;
	tmp = s;
	while (tmp)
	{
		i = -1;
		while (tmp->execve && tmp->execve[++i])
			free(tmp->execve[i]);
		free(tmp->execve);
		free(tmp->str);
		tmp->str = NULL;
		free(tmp);
		tmp = tmp->next;
	}
}

void	ft_free_all(void)
{
	int		i;

	i = -1;
	close(g_o.pipe[0]);
	close(g_o.pipe[1]);
	close(g_o.fd_in);
	close(g_o.fd_out);
	while (g_o.split && g_o.split[++i])
		free(g_o.split[i]);
	free(g_o.split);
	ft_free_struct(g_o.args);
	ft_free_struct(g_o.final);
	ft_init_struct(0);
}

void	ft_free_mass(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
