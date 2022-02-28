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

typedef struct s_shell
{
	char		**env;
	char		**args;
	char		*line;
	int			exit;
	int			exit_status;
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
/*
char			*convertocd(char **str);

// Builtins Utils
int				envpos(char **env, char *path);
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
void			unsent(char ***envv, char *path);
void			export(char ***envv, char *path);
int				pwd(char **env, bool print);
void			cd(char **env, char *path);
void			envb(char **env);
char			*echo(char **env, char *path);
*/
#endif