#include "minishell.h"

int	count_pipes(char	**a)
{
	int	i;
	int	n;
	int	last_was_pipe;

	last_was_pipe = 0;
	i = 0;
	n = 0;
	while (a[i])
	{
		if (a[i][0] == '|' && last_was_pipe == 0)
		{
			last_was_pipe = 1;
			n++;
		}
		else if (a[i][0] == '|' && last_was_pipe == 1)
			return (-1);
		else
			last_was_pipe = 0;
		i++;
	}
	return (n);
}

void	fill_nodes(t_node	*nodes, char **a)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = i;
	k = j;
	nodes[j].cmd = ft_strdup(a[i]);
	while (a[i])
	{
		printf("->%s\n", nodes[j].cmd);
		if (ft_strlen(a[i]) == 1 && a[i][0] == '|' && i != 0)
		{
			j++;
			i++;
			k = 0;
			nodes[j].cmd = ft_strdup(a[i]);
		}
		nodes[j].in_file = 0;
		nodes[j].out_file = 1;
		nodes[j].arg = NULL;
		matrix_replace_i(&nodes[j].arg, &a[i], k + 1);
		i++;
		k++;
	}
}

t_node	*parse(char	**a)
{
	t_node	*nodes;
	int		num_pipes;

	num_pipes = count_pipes(a);
	nodes = malloc((num_pipes + 1) * sizeof(t_node));
	fill_nodes(nodes, a);
	printf("number of pipes = %d\n", num_pipes);
	return (nodes);
}
