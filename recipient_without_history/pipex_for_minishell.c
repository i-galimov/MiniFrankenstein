/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_for_minishell.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:48:43 by phella            #+#    #+#             */
/*   Updated: 2022/06/06 21:42:52 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

char	*ft_path(char *cmd, char **env)
{
	int		i;
	char	**all_paths;
	char	*piece_path;
	char	*res;

	i = 0;
	if (env == NULL)
		exit (1);
	while (env[i] && ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	if (env[i] == NULL)
		return (0);
	all_paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (all_paths[++i])
	{
		piece_path = ft_strjoin(all_paths[i], "/");
		res = ft_strjoin(piece_path, cmd);
		if (access(res, F_OK) == 0)
			return (res);
		else
			free(res);
	}
	return (0);
}

void	ft_get_cmd(char *argv, char **env)
{
	char	**cmd;
	char	**cmd2;
	char	*path;
	int		i;

	i = 0;
	cmd2 = ft_split(argv, ' ');
	cmd = ft_split(argv, ' ');
	if (access(cmd[0], X_OK) == 0)
	{	
		cmd = ft_split(argv, '/');
		while (cmd[i])
			i++;
		cmd = ft_split(cmd[i - 1], ' ');
		execve(cmd2[0], cmd, env);
	}
	path = ft_path(cmd[0], env);
	if (execve(path, cmd, env) == -1)
	{
		perror("Command error");
		exit(1);
	}
}

void	ft_parent_process(char **argv, char **env, int *fd)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		write(2, "Permission denied error\n", 24);
		exit(1);
	}
	dup2(fd[0], 0);
	dup2(fd_out, 1);
	close(fd[1]);
	ft_get_cmd(argv[3], env);
}

void	ft_child_process(char **argv, char **env, int *fd)
{
	(void)fd;
	ft_get_cmd(argv[0], env);
}

int	ft_fork_work(int argc, char *argv[], char **env)
{
	int		pid;
	int		fd[2];

	(void)argc;
	pid = fork();
	if (pipe(fd) == -1)
	{
		perror("Pipe error");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Fork error");
		exit(1);
	}
	if (pid == 0)
		ft_child_process(argv, env, fd);
	return (0);
}
