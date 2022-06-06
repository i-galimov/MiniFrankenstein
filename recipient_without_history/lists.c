/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtire <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:00:17 by rtire             #+#    #+#             */
/*   Updated: 2022/06/05 19:00:20 by rtire            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	if (!new || !lst)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

t_lst	*ft_lstnew(void *content)
{
	t_lst	*head;

	head = (t_lst *)malloc(sizeof(t_lst));
	if (!head)
		return (NULL);
	head -> next = NULL;
	head -> str = content;
	head -> flag_meta = 0;
	head -> pipe_flag = 0;
	head -> fd_in = -2;
	head -> fd_out = -2;
	head -> execve = NULL;
	return (head);
}

int	ft_lstsize(t_lst *lst)
{
	int		len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		len++;
		lst = lst -> next;
	}
	return (len);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	if (!lst)
		return (lst);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}
