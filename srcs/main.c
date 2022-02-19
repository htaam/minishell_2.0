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

	nodes = NULL;
	(void)argc;
	(void)argv;
	(void)envp;
	line = 0;
	line = rl_w_history("minishell$ ", line);
	if (ft_strncmp("exit", line, 5) == 0)
		exit (0);
	a = ft_cmdtrim(line, " ");
	a = ft_subsplit(a);
	expander(a);
	remove_quotes(a);
	nodes = parse(a);
	print_node(nodes, a);
	printf("end\n");
	free_nodes(nodes, count_pipes(a));
	ft_freecharmatrix(a);
	free(a);
	free(line);
	return (0);
}
