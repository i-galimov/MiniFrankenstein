/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buildin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:47:05 by phella            #+#    #+#             */
/*   Updated: 2022/06/06 15:56:45 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

int	check_buildin(char *line, t_env *e)
{
	if (!ft_strncmp(line, "pwd", ft_strlen("pwd")))
	{
		ft_pwd(e);
		return (1);
	}
	if (!ft_strncmp(line, "env", ft_strlen("env")))
	{
		ft_env(e);
		return (1);
	}
	if (!ft_strncmp(line, "echo", ft_strlen("echo")))
	{
		ft_echo(line);
		return (1);
	}
	if (!ft_strncmp(line, "cd", ft_strlen("cd")))
	{
		ft_cd(line, e);
		return (1);
	}
	else
		return (check_buildin2(line, e));
	return (0);
}

int	check_buildin2(char *line, t_env *e)
{
	if (!ft_strncmp(line, "exit", ft_strlen("exit")))
	{
		ft_exit(line);
		return (1);
	}
	if (!ft_strncmp(line, "export", ft_strlen("export")))
	{
		ft_export(line, e);
		return (1);
	}
	if (!ft_strncmp(line, "unset", ft_strlen("unset")))
	{
		ft_unset(e, line);
		return (1);
	}
	return (0);
}
