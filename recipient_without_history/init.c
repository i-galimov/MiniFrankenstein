/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtire <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:37:31 by rtire             #+#    #+#             */
/*   Updated: 2022/06/04 19:37:34 by rtire            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_env(char **env)
{
	int	i;

	i = -1;
	g_o.count_env = 0;
	while (env[g_o.count_env])
		g_o.count_env++;
	if (g_o.count_env > 0)
	{
		g_o.env = malloc(sizeof(char *) * g_o.count_env + 1);
		while (++i < g_o.count_env)
			g_o.env[i] = ft_strdup(env[i]);
		g_o.env[i] = NULL;
	}
	else
	{
		write(2, "bad_env\n", 8);
		ft_free_all();
		return ;
	}
}

void	ft_init_struct(int flag)
{
	if (flag)
	{
		g_o.env = NULL;
		g_o.ex_code = 0;
		g_o.count_env = 0;
	}
	g_o.input = NULL;
	g_o.fd_in = -2;
	g_o.fd_out = -2;
	g_o.pipe[0] = -2;
	g_o.pipe[1] = -2;
	g_o.count = 0;
	g_o.args = NULL;
	g_o.final = NULL;
	g_o.split = NULL;
	g_o.count_final = 0;
	g_o.buildin_flag = 0;
	g_o.final_args = NULL;
}
