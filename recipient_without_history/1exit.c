#include "minishell.h"

void	ft_exit_code_plus(t_lst *tmp)
{
	if (ft_atoi(tmp->execve[1]) < 0)
	{
		g_o.ex_code = 256 + ft_atoi(tmp->execve[1]);
		while (g_o.ex_code < 0)
			g_o.ex_code += 256;
	}
	else
		g_o.ex_code = ft_atoi(tmp->execve[1]) % 255;
}

int	ft_check_num(char	*token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (!ft_isdigit(token[i]) && token[0] != '-')
			return (1);
		i++;
	}
	return (0);
}

int	ft_exit(t_lst *tmp)
{
	int	i;

	i = 0;
	while (tmp->execve[i])
		i++;
	if (i == 1)
		return (0);
	if (ft_check_num(tmp->execve[1]) || ft_strlen(tmp->execve[1]) > 18)
	{
		printf("exit: %s: numeric argument required\n", tmp->execve[1]);
		g_o.ex_code = 255;
		return (0);
	}
	if (i > 2)
	{
		printf("exit: too many arguments\n");
		g_o.ex_code = 1;
		return (1);
	}
	ft_exit_code_plus(tmp);
	return (0);
}
