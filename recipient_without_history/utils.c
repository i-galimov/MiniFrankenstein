/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtire <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:31:55 by rtire             #+#    #+#             */
/*   Updated: 2022/06/04 19:32:00 by rtire            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_sjoin(char *s1, char *s2, int flag, int flag2)
{
	int		i;
	int		j;
	char	*res;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	res = malloc(sizeof(*res) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i >= 0 && s1 && s1[i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	if (flag)
		free(s1);
	if (flag2)
		free(s2);
	return (res);
}

char	*ft_substr_m(char *s, int start, int len, int flag)
{
	int		i;
	int		j;
	char	*res;

	if (!s)
		return (0);
	i = ft_strlen(s);
	if (i < len)
		len = i;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
		if (i >= start && j < len)
			res[j++] = s[i];
	res[j] = '\0';
	if (flag)
		free(s);
	return (res);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (s1 == NULL)
		return (1);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1 ++;
		s2 ++;
	}
	return (0);
}

t_lst	*ft_put_lst_new(void)
{
	int		i;
	t_lst	*head;

	i = -1;
	head = (t_lst *)malloc(sizeof(t_lst));
	if (!head)
		return (NULL);
	head -> next = NULL;
	head -> str = NULL;
	head -> flag_meta = 0;
	head -> pipe_flag = 0;
	head -> fd_in = g_o.fd_in;
	head -> fd_out = g_o.fd_out;
	g_o.fd_in = -2;
	g_o.fd_out = -2;
	head -> execve = malloc(sizeof(char *) * g_o.count_final + 1);
	while (g_o.final_args[++i])
		head->execve[i] = ft_strdup(g_o.final_args[i]);
	head->execve[i] = NULL;
	i = -1;
	while (g_o.final_args[++i])
		free(g_o.final_args[i]);
	free(g_o.final_args);
	return (head);
}
