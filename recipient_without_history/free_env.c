/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:58:51 by phella            #+#    #+#             */
/*   Updated: 2022/06/06 21:11:38 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildin.h"

void	free_env(t_env *e)
{
	int	i;

	i = -1;
	while (e->env2[++i])
		free(e->env2[i]);
	free(e->env2);
	i = -1;
	while (e->sort_env2[++i])
		free(e->sort_env2[i]);
	free(e->sort_env2);
	i = -1;
	while (e->key_env[++i])
		free(e->key_env[i]);
	free(e->key_env);
		i = -1;
	while (e->value_env[++i])
		free(e->value_env[i]);
	free(e->value_env);
}
