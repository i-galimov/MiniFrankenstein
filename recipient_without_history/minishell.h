/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:13:09 by rtire             #+#    #+#             */
/*   Updated: 2022/06/05 16:41:55 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

# define BLUE "\033[0;34m"
# define WHITE "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"

# define BLUE "\033[0;34m"
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
	char	*history_log;
	char	**final_args;
	int		fd_in;
	int		count;
	int		fd_out;
	int		pipe[2];
	int		ex_code;
	int		count_env;
	int		count_final;
	int		buildin_flag;
	int		build_pipe[2];
	t_lst	*args;
//	t_log	*page;
	t_lst	*final;
//	t_log	*first;
}	t_o;

t_o	g_o;

void	ft_init_struct(int flag);
void	ft_init_env(char **env);
void	ft_free_all(void);
void	ft_free_struct(t_lst *s);
void	ft_shlvl(void);
char	**ft_join_shlvl(void);
void	ft_free_mass(char **str);
char	*ft_sjoin(char *s1, char *s2, int flag, int flag2);
void	ft_loop(void);
void	ft_proc_signal_handler(int signum);
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

// 1list_ops.c
int	ft_lstsize3(t_lst *lst);
t_lst	*ft_lstlast3(t_lst *lst);
void	ft_lstadd_back3(t_lst **lst, t_lst *new);
t_lst	*ft_lstnew3(void *content);
// 1multyexe.c
void	ft_wait(int *pid, int pipe_fd[2][2]);
t_lst	*ft_first_proc(t_lst *tmp, int i, int *pid, int pipe_fd[2][2]);
t_lst	*ft_second_proc(t_lst *tmp, int *i, int *pid, int pipe_fd[2][2]);
void	ft_exe(t_lst *tmp, int *pid, int pipe_fd[2][2]);
void	ft_multiexe(void);
// 1ft_exit.c
void	ft_exit_code_plus(t_lst *tmp);
int		ft_check_num(char	*token);
int		ft_exit(t_lst *tmp);
// 1exe_utils.c
void	ft_get_path(t_lst *tmp, int i);
char	*ft_find_path(t_lst *tmp);
void	ft_dup(t_lst *tmp, int i, int pipe_fd[2][2]);
void	ft_dup2(t_lst *tmp, int i, int pipe_fd[2][2]);
int		ft_interceptor(t_lst *tmp, int *pipe_fd);

// 1cd.c
void	ft_flag_action(char *path_env, char *old_path_env, int flag);
void	ft_change_pwd(char *path, char *old_path);
int		ft_find_home(void);
void	ft_return_home(void);
void	ft_cd(t_lst *tmp);
// cd_utils.c
void	ft_export_add_check(char *arg);
int		ft_check_oldpwd(void);
// 1env.c
void	ft_env(t_lst *tmp, int *pipe);
// 1exit.c
void	ft_exit_code_plus(t_lst *tmp);
int		ft_check_num(char	*token);
int		ft_exit(t_lst *tmp);
// 1export_utils.c
int		ft_masslen(char **str);
void	ft_export_add_env(char *arg, int len);
void	ft_export_new_env(char *arg);
int		ft_export_error_check(char *arg);
void	ft_export_add(char *arg);
// 1export_utils2.c
void	ft_check_out_builtin(t_lst *tmp, int *fd, int *pipe);
void	ft_replace_env(char *arg, char *buf, int i);
// 1export.c
void	ft_print_env(char **env, t_lst *tmp, int *pipe);
void	ft_swap(char **env, int i, int *flag);
void	ft_sort_env(char **env, t_lst *tmp, int *pipe);
void	ft_export(t_lst *tmp, int *pipe);
// 1pwd.c
void	ft_pwd(t_lst *tmp, int *pipe);
// 1unset.c
void	ft_env_tail(int i);
int		ft_unset_error_check(char *arg);
void	ft_unset_env(char *arg);
void	ft_unset(t_lst *tmp);
// 1echo.c
void	ft_check_flag_n(t_lst *tmp, int *i, int *flag);
void	ft_echo(t_lst *tmp, int *pipe);
// 1ft_join.c
char	*ft_check_flag(int flag, int i, int k);
char	*ft_join(char const *s1, char const *s2, int flag);


#endif