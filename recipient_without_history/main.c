/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:47:12 by rtire             #+#    #+#             */
/*   Updated: 2022/06/05 15:31:04 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_loop(void)
{
	while (1)
	{
		ft_signals();
		g_o.input = readline(GREEN"minizhopa-> "WHITE);
		if (!g_o.input)
		{
			printf("exit\n");
			break ;
		}
		if (!g_o.input[0])
		{
			free(g_o.input);
			continue ;
		}
		add_history(g_o.input);
		ft_preparsing();
		if (g_o.final && !ft_strcmp(g_o.final->execve[0], "exit")
			&& ft_lstsize3(g_o.final) == 1)
			if (!ft_exit(g_o.final))
				break ;
		ft_multiexe();
		ft_free_all();
	}
}

int	main(int argc, char *argv[], char **env)
{
	(void)argc;
	(void)argv;
	ft_init_struct(1);
	ft_init_env(env);
	ft_shlvl();
	ft_loop();
//	int i = -1;
//	while (++i < g_o.count_env)
//		printf("->%s\n", env[i]);
}
