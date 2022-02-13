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
	int	i;
	int	j;

	i = 0;
	j = i;
	while (a[i])
	{
		
		i++;
	}
}

t_node	*parse(char	**a)
{
	t_node	*nodes;
	int		num_pipes;
	int		i;
	nodes = NULL;
	num_pipes = count_pipes(a);
	nodes = malloc((num_pipes + 1) * sizeof(t_node));
	fill_nodes(nodes, a);
	printf("number of pipes = %d\n", num_pipes);
	return (nodes);
}
