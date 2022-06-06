/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:47:33 by phella            #+#    #+#             */
/*   Updated: 2022/06/06 15:57:49 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

int	check_export(char *line)
{
	if (line[0] == 'e')
		if (line[1] == 'x')
			if (line[2] == 'p')
				if (line[3] == 'o')
					if (line[4] == 'r')
						if (line[5] == 't')
							if (!line[6])
								return (1);
	return (0);
}

void	ft_env(t_env *e)
{
	int	i;

	i = 0;
	while (e->env2[i])
	{
		if (e->env2[i][0] != '\0')
			printf ("%s\n", e->env2[i]);
		i++;
	}
}
