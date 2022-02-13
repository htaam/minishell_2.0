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

typedef struct s_cmd
{
	struct s_cmd	*prev;
	char			*cmd;
	struct s_cmd	*next;
}			t_cmd;

typedef struct s_shell
{
	char		**env;
	char		**args;
	t_cmd		*cmd;
	char		*line;
}				t_shell;

typedef struct s_node
{
	char	**arg;
	char	*cmd;
	int		in_file;
	int		out_file;
}	t_node;

char	*rl_w_history(char *prompt, char *line_read);
char	**ft_cmdtrim(char const *s, char *set);
void	expander(char	**a);
char	**ft_subsplit(char	**a);
void	remove_quotes(char	**a);
t_node	*parse(char	**a);

#endif