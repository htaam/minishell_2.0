#include "minishell.h"

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

int	main(int argc, char **argv, char **envp)
{
	char		**a;
	char		*line;
	t_node		**nodes;
	int			n_nodes;
	pid_t		pid;

	nodes = NULL;
	(void)argc;
	(void)argv;
	(void)envp;
	int i = 0;
	while (i < 3)
	{
		line = 0;
		pid = fork();
		if (pid == 0)
		{
			line = rl_w_history("minishell$ ", line);
			a = ft_cmdtrim(line, " ");
			a = ft_subsplit(a);
			expander(a);
			remove_quotes(a);
			nodes = parse(a);
			n_nodes = count_pipes(a) + 1;
			executor(nodes, n_nodes);
			printf("ola\n");
			free_nodes(nodes, count_pipes(a));
			ft_freecharmatrix(a);
			free(a);
			free(line);
			return (0);
		}
		else
			waitpid(pid, NULL, 0);
		i++;
	}
	return (0);
}
