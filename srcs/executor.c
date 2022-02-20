#include "minishell.h"

void	executor_2(t_node *node, int i, int **fd, int n_nodes)
{
	(void)node;
	printf("1 CHILD %d\n", i);
	if (i < n_nodes && n_nodes > 1)
		dup2(fd[i][1], 1);
	printf("2 CHILD %d\n", i);
	if (i > 0)
		dup2(fd[i - 1][0], 0);
	if (i == n_nodes)
		dup2(1,1);
	printf("3 CHILD %d\n", i);
}

void	executor(t_node **nodes, int n_nodes)
{
	int		i;
	int		**fd;
	pid_t	pid;

	i = 0;
	if (n_nodes > 1)
	{
		fd = ft_calloc(sizeof(int *) * 2, n_nodes - 1);
		while (i < n_nodes)
		{
			fd[i] = malloc (sizeof(int) * 2);
			pipe(fd[i]);
			printf("\n\ni = %d, fd[0] = %d  fd[1] = %d\n\n", i, fd[i][0], fd[i][1]);
			i++;
		}
	}
	i = 0;
	while (i < n_nodes)
	{
		printf("AQUI %d\n", i);
		pid = fork();
		if (pid == 0)
		{
			executor_2(nodes[i], i, fd, n_nodes);
			exit(0);
		}
		else
			wait(NULL);
		i++;
	}
}
