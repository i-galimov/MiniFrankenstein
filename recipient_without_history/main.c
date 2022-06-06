/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:47:12 by rtire             #+#    #+#             */
/*   Updated: 2022/06/06 23:50:25 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_buildins(t_env *e, int pid, char **env)
{
	if (g_o.input && *g_o.input && !check_buildin(g_o.input, e) \
			&& !var_env_parser(e, g_o.input))
	{
		pid = fork();
		if (pid == 0)
			ft_get_cmd(g_o.input, env);
		waitpid(0, 0, 0);
	}
}

void	ft_loop(char **env)
{
	int		pid;
	t_env	e;

	pid = 0;
	while (1)
	{
		ft_signals();
		g_o.input = readline(GREEN"minishell-> "WHITE);
		if (!g_o.input)
		{
			printf("\x1B[1A\x1B[12C""exit\n");
			break ;
		}
		if (!g_o.input[0])
		{
			free(g_o.input);
			continue ;
		}
		add_history(g_o.input);
		ft_preparsing();
		ft_buildins(&e, pid, env);
		ft_free_all();
		free(g_o.input);
	}
	free_env(&e);
}

int	main(int argc, char *argv[], char **env)
{
	(void)argc;
	(void)argv;
	ft_init_struct(1);
	ft_init_env(env);
	if (ft_minizhopa(env))
		return (1);
	ft_loop(env);
	return (0);
}
