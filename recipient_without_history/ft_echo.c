/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:47:25 by phella            #+#    #+#             */
/*   Updated: 2022/06/06 15:50:19 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

int	check_echo(char *line)
{
	if (line[0] == 'e')
		if (line[1] == 'c')
			if (line[2] == 'h')
				if (line[3] == 'o')
					if (line[4] == ' ')
						return (1);
	return (0);
}

int	check_echo_n(char *line)
{
	if (line[5] == '-')
		if (line[6] == 'n')
			if (line[7] == ' ')
				return (1);
	return (0);
}

void	ft_echo(char *line)
{	
	int	i;

	i = 7;
	if (check_echo(line) && check_echo_n(line))
	{
		while (line[i++])
			printf("%c", line[i]);
	}
	i = 4;
	if (!check_echo_n(line) && check_echo(line))
	{
		while (line[i++])
			printf("%c", line[i]);
		printf("%c", '\n');
	}
}
