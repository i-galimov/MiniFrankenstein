/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:15:16 by kferterb          #+#    #+#             */
/*   Updated: 2022/04/26 13:39:11 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_pwd(t_lst *tmp, int *pipe)
{
	int		fd;
	char	*path;

	fd = 1;
	path = NULL;
	path = getcwd(path, 1000);
	ft_check_out_builtin(tmp, &fd, pipe);
	write(fd, path, ft_strlen(path));
	write(fd, "\n", 1);
	free(path);
}
