/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:13:09 by rtire             #+#    #+#             */
/*   Updated: 2022/06/06 23:24:33 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "buildin.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <fcntl.h>

# define GREEN "\033[0;32m"
# define WHITE "\033[0m"

typedef struct s_lst
{
	int				fd_in;
	int				fd_out;
	char			**execve;
	char			*str;
	int				pipe_flag;
	int				flag_meta;
	struct s_lst	*next;
}	t_lst;

typedef struct s_o
{
	char	**env;
	char	*input;
	char	**split;
	char	**final_args;
	int		fd_in;
	int		count;
	int		fd_out;
	int		pipe[2];
	int		ex_code;
	int		count_env;
	int		count_final;
	int		buildin_flag;
	t_lst	*args;
	t_lst	*final;
}	t_o;

t_o	g_o;

void	ft_init_struct(int flag);
void	ft_init_env(char **env);
void	ft_free_all(void);
void	ft_free_struct(t_lst *s);
char	*ft_sjoin(char *s1, char *s2, int flag, int flag2);
void	ft_loop(char **env);
void	ft_signals(void);
void	ft_handler(int sig);
void	ft_preparsing(void);
char	**ft_split_mod(char *s, char c);
int		ft_count_word_mod(char *s, char c);
char	*ft_substr_m(char *s, int start, int len, int flag);
int		ft_strcmp(char *s1, char *s2);
char	*ft_parse_quotes(t_lst *o, int *j, char c);
int		ft_check_quotes(char *s, int *index, char c);
char	*find_dollar(char *str);
char	*ft_parse_dollar(char *str, int *index);
char	*ft_find_env(char *s);
char	**ft_fill_word_mod(char *s, char c, int count, char **str);
int		ft_len_word_mod(char *s, char c);
void	*ft_mem_free_mod(char **str, int count);
void	ft_check_list(void);
int		ft_check_redirects(t_lst *tmp);
int		ft_start_preparse(t_lst *tmp);
void	ft_put_redirect_to_list(t_lst *tmp, int *i);
void	ft_if(t_lst *tmp, char *start, int *i);
void	ft_else(t_lst *tmp, int *i);
void	ft_concatenator(t_lst *tmp, t_lst *tmp2);
void	ft_parsing(void);
char	*ft_redirects(t_lst *o, int *j);
char	*ft_parse_redirect(t_lst *o, int flag, int flag2);
char	*ft_parse_lite(t_lst *o, int flag, int flag2);
int		ft_check_syntax(t_lst *o);
void	ft_check_parse(t_lst *o);
void	ft_heredoc(t_lst *o);
void	ft_check_heredoc(t_lst *o);
void	ft_put_list(int flag);
void	ft_check_put_list(int flag);
void	ft_put_final_args(void);
t_lst	*ft_put_lst_new(void);
int		ft_open_file(t_lst *o, int flag);
void	ft_lstadd_back(t_lst **lst, t_lst *new);
t_lst	*ft_lstnew(void *content);
t_lst	*ft_lstlast(t_lst *lst);
int		ft_minizhopa(char **env);
void	ft_buildins(t_env *e, int pid, char **env);

#endif