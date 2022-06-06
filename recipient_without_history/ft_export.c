/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:47:50 by phella            #+#    #+#             */
/*   Updated: 2022/06/06 15:59:48 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

int	check_export_var(char *line)
{
	if (!ft_strncmp(line, "export ", ft_strlen("export ")))
	{
		if (ft_isalpha(line[7]) || line[7] == '_')
			return (1);
		else
		{
			printf("export: ");
			printf("%s", line + 7);
			printf(": not a valid identifier\n");
		}
	}
	return (0);
}

void	ft_sort_alph(t_env *e)
{
	if (e->sort_env2[e->i][0] == e->sort_env2[e->i + 1][0])
	{
		e->j = 1;
		while (e->sort_env2[e->i][e->j] == e->sort_env2[e->i + 1][e->j])
			e->j++;
		if (e->sort_env2[e->i][e->j] && e->sort_env2[e->i + 1][e->j] && \
					e->sort_env2[e->i][e->j] > e->sort_env2[e->i + 1][e->j])
		{
			e->temp = e->sort_env2[e->i];
			e->sort_env2[e->i] = e->sort_env2[e->i + 1];
			e->sort_env2[e->i + 1] = e->temp;
			e->flag = 1;
		}
	}
	else if (e->sort_env2[e->i][0] > e->sort_env2[e->i + 1][0])
	{
		e->temp = e->sort_env2[e->i];
		e->sort_env2[e->i] = e->sort_env2[e->i + 1];
		e->sort_env2[e->i + 1] = e->temp;
		e->flag = 1;
	}
}

void	sort_env(t_env *e)
{
	e->flag = 1;
	while (e->flag == 1)
	{
		e->i = -1;
		e->flag = 0;
		while (++e->i < e->count_var - 1)
			ft_sort_alph(e);
	}
}

void	ft_inside_export(char *line, t_env *e)
{
	int	i;
	int	flag;

	i = -1;
	if (check_export_var(line))
	{
		while (line[++i])
		{
			if (line[i] == '=')
			{
				flag = 1;
				e->count_var += 1;
				e->count_sort_var += 1;
				temp_sort_env(e, line);
				temp_env(e, line);
			}
		}
		if (flag == 0)
			temp_sort_env(e, line);
	}
}

void	ft_export(char *line, t_env *e)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	if (check_export(line))
	{
		sort_env(e);
		while (e->sort_env2[++i])
		{
			printf("declare -X ");
			printf("%s\n", e->sort_env2[i]);
		}
	}
	ft_inside_export(line, e);
}
