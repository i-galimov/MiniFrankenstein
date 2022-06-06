/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:48:58 by phella            #+#    #+#             */
/*   Updated: 2022/06/06 23:22:32 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

void	save_env(char **env, t_env *e)
{
	int		i;
	char	**temp;

	i = -1;
	while (env[++i])
	{
		e->env2[i] = ft_strdup(env[i]);
		e->sort_env2[i] = ft_strdup(env[i]);
		temp = ft_split(env[i], '=');
		e->key_env[i] = temp[0];
		e->value_env[i] = temp[1];
		free_arr(temp);
		e->count_var = i;
	}
	e->env2[i] = NULL;
	e->key_env[i] = NULL;
	e->value_env[i] = NULL;
	e->sort_env2[i] = NULL;
	e->count_sort_var = e->count_var;
	save_pwd(e);
	save_home(e);
}

int	size_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void	save_pwd(t_env *e)
{
	int		i;
	char	dir[500];

	i = -1;
	getcwd(dir, 500);
	e->pwd = ft_strdup(dir);
}

void	save_home(t_env *e)
{
	int	i;

	i = -1;
	while (e->env2[++i])
	{
		if (ft_strncmp(e->env2[i], "HOME=", ft_strlen("HOME=")))
		{
			e->home = ft_strdup(e->env2[i]);
			break ;
		}
	}
}
