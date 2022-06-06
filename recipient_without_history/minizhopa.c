/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minizhopa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:48:32 by phella            #+#    #+#             */
/*   Updated: 2022/06/06 15:48:34 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

int	ft_minizhopa(char **env)
{
	t_env	e;

	e.env2 = malloc(sizeof(char *) * size_env(env) + 1);
	e.sort_env2 = malloc(sizeof(char *) * size_env(env) + 1);
	e.key_env = malloc(sizeof(char *) * size_env(env) + 1);
	e.value_env = malloc(sizeof(char *) * size_env(env) + 1);
	if (!e.env2 || !e.sort_env2 || !e.key_env || !e.value_env)
		return (1);
	save_env(env, &e);
	return (0);
}
