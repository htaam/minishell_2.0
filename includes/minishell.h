/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:38:51 by tmatias           #+#    #+#             */
/*   Updated: 2022/04/10 16:51:07 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include <sys/wait.h>
# include <stdbool.h>
# include <termios.h>
# include <dirent.h>

typedef struct s_shell
{
	char		**env;
	char		**args;
	char		*line;
	int			exit;
	int			exit_status;
	int			exit_pipe[2];
}				t_shell;

typedef struct s_node
{
	char	**arg;
	char	*cmd;
	int		in_file;
	int		out_file;
}	t_node;

typedef struct s_nodelist
{
	t_node				node;
	struct s_nodelist	*next;
}			t_nodelist;

extern t_shell	g_shell;

char			*rl_w_history(char *prompt, char *line_read);
char			**ft_cmdtrim(char const *s, char *set);
void			expander(char	**a);
char			**ft_subsplit(char	**a);
void			remove_quotes(char	**a);
t_node			**parse(char	**a);
char			**matrix_replace_i(char ***big, char **small, int n);
int				count_pipes(char	**a);
void			executor(t_node **nodes, int n_nodes);
void			do_exeve(char	*cmd, char	**arg, int **fd, int *info);
void			init_env(char **envp);
char			*do_quotes_expand(char *list);
char			*do_expand_aux_2(char *list);
char			*my_get_env(char *s);
int				my_get_pos(char *s);
void			close_extra_pipes(int **fd, int i, int n_nodes);
void			sig_handle2(int signal);

void			difbuilt(char **argu);

//Builtins Utils
void			cdv(char *path);
int				my_get_pos(char *s);
void			difbuiltt(char **argu);
int				checkpos(char *str, char c);
void			convertminmai(char *str, int conv);
int				envpos(char *path);
int				clchar(char c, char *str);
unsigned int	bdstrcount(char **str);
int				ft_strcmp(const char *s1, const char *s2);
int				firstequals(char *s1, char *s2);
void			ft_strcpy(char *dest, char *src);
void			ordenv(char **env);
char			*ft_substrsc(char *s, unsigned int start, size_t len);
void			cdf(char **env, char *initialpath, int oldpwd, int pwdpos);
int				ft_rstrcmp(const char *s1, const char *s2);

// Builtins
void			unsent(char *path);
void			export(char *path);
int				pwd(char **env, bool print);
void			cd(char *path);
void			envb(char **env);
char			*echo(char *path);
void			convertminmai(char *str, int conv);

void			whileexport(char **argu);
void			tryexport(char *path);
int				lencalc(char *s, int start);
#endif
