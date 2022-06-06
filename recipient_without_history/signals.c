/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtire <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 00:19:07 by rtire             #+#    #+#             */
/*   Updated: 2022/06/05 00:19:11 by rtire            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_handler(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
	write(1, "  \n", 3);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_signals(void)
{
	struct sigaction	sa;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	sa.sa_handler = ft_handler;
	sigaction(SIGINT, &sa, NULL);
}
