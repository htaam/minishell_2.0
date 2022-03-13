#include "minishell.h"

/* global variable declaration */
t_shell	g_shell;

void	print_node(t_node **nodes, char **a)
{
	int	i;
	int	j;

	i = 0;
	while (i <= count_pipes(a))
	{
		printf("cmd[%d] > %s\n", i, nodes[i]->cmd);
		printf("in_file[%d] > %d\n", i, nodes[i]->in_file);
		printf("out_file[%d] > %d\n", i, nodes[i]->out_file);
		j = 0;
		while ((nodes[i]->arg[j]))
		{
			printf("arg[%d] > %s\n", j, nodes[i]->arg[j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	free_nodes(t_node **node, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		ft_free_matrix(&node[i]->arg);
		free(node[i]->cmd);
		free(node[i]);
		i++;
	}
	free(node);
}

int	is_line_empty(char	*line)
{
	int	a;
	a = 0;

	while(line[a])
	{
		if (line[a]!= ' ')
			return(0);
		a++;
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char		**a;
	char		*line;
	t_node		**nodes;

	g_shell.exit = 0;
	nodes = NULL;
	(void)argc;
	(void)argv;
	init_env(envp);
	while (g_shell.exit == 0)
	{
		line = 0;
		line = rl_w_history("Prompt minishell$ ", line);
		if (is_line_empty(line) == 0)
		{
			a = ft_cmdtrim(line, " ");
			a = ft_subsplit(a);
			expander(a);
			remove_quotes(a);
			nodes = parse(a);
			//print_node(nodes, a);
			executor(nodes, count_pipes(a) + 1);
			free_nodes(nodes, count_pipes(a));
			ft_freecharmatrix(a);
			free(a);
		}
		free(line);
	}
	return (0);
}
