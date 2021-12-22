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
	int		in_fd;
	int		out_fd;
	char	*in_name;
	char	*out_name;
	char	*line;
	char	**args;
}				t_cmd;

typedef struct s_shell
{
	char	**env;
	char	**args;
	t_cmd	*cmd;
	char	*line;
}				t_shell;

extern t_shell	g_shell;

char	*rl_w_history(char *prompt, char *line_read);

#endif