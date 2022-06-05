#include "minishell.h"

int	ft_lstsize3(t_lst *lst)
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

t_lst	*ft_lstlast3(t_lst *lst)
{
	if (!lst)
		return (lst);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_lstadd_back3(t_lst **lst, t_lst *new)
{
	if (!new || !lst)
		return ;
	if (*lst)
		ft_lstlast3(*lst)->next = new;
	else
		*lst = new;
}

t_lst	*ft_lstnew3(void *content)
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
