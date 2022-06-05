#include "minishell.h"

void	ft_env(t_lst *tmp, int *pipe)
{
	int	i;
	int	fd;

	i = -1;
	fd = 1;
	ft_check_out_builtin(tmp, &fd, pipe);
	while (g_o.env[++i])
	{
		write(fd, g_o.env[i], ft_strlen(g_o.env[i]));
		write(fd, "\n", 1);
	}
}