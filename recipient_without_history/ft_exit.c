/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:47:42 by phella            #+#    #+#             */
/*   Updated: 2022/06/06 15:47:44 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

int	check_exit(char *line)
{
	if (!ft_strncmp(line, "exit", ft_strlen("exit")))
	{
		if (!line[4])
			exit(0);
		else if (line[4] == ' ')
			return (check_exit_d(line));
	}
	return (0);
}

int	check_exit_d(char *line)
{
	int	i;

	i = 5;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			i++;
		else if (!ft_isdigit(line[i]))
		{
			printf("exit: ");
			printf("%s", line + 5);
			printf(": numeric argument required\n");
			return (0);
		}
	}
	return (1);
}

void	ft_exit(char *line)
{	
	int	exit_code;

	if (check_exit(line))
	{
		exit_code = ft_atoi(line + 5);
		while (exit_code >= 256)
			exit_code %= 256;
		exit(exit_code);
	}
}
