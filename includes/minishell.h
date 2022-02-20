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

typedef struct s_shell
{
	char		**env;
	char		**args;
	char		*line;
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

char		*rl_w_history(char *prompt, char *line_read);
char		**ft_cmdtrim(char const *s, char *set);
void		expander(char	**a);
char		**ft_subsplit(char	**a);
void		remove_quotes(char	**a);
t_node		**parse(char	**a);
char		**matrix_replace_i(char ***big, char **small, int n);
int			count_pipes(char	**a);
void		executor(t_node **nodes, int n_nodes);

#endif