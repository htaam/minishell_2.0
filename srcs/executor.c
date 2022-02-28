#include "minishell.h"

void	executor_2(t_node *node, int i, int **fd, int n_nodes)
{
	int		og_one;
	int		og_zero;
	int		info[2];

	info[0] = i;
	info[1] = n_nodes;

	og_one = dup(1);
	og_zero = dup(0);
	(void)node;
	if (i < n_nodes - 1 && n_nodes > 1)
		dup2(fd[i][1], 1);
	if (i > 0)
	{
		dup2(fd[i - 1][0], 0);
		close(fd[i - 1][1]);
	}
	/*if (0 == ft_strncmp(node->cmd, "echo", 4))
		printf("do ECHO\n");
	else if (0 == ft_strncmp(node->cmd, "export", 6))
		printf("do export\n");
	else if (0 == ft_strncmp(node->cmd, "unset", 5))
		printf("do unset\n");
	else if (0 == ft_strncmp(node->cmd, "cd", 2))
		printf("do cd\n");
	else if (0 == ft_strncmp(node->cmd, "exit", 4))
		g_shell.exit = 1;
	else if (0 == ft_strncmp(node->cmd, "pwd", 3))
		printf("do pwd\n");
	else if (0 == ft_strncmp(node->cmd, "env", 3))
		printf("do env\n");
	else*/
	if (0 == ft_strncmp(node->cmd, "exit", 4))
		g_shell.exit = 1;
	else
		do_exeve(node->cmd, node->arg, fd, info);
	dup2(og_zero, 0);
	dup2(og_one, 1);
}

void	close_pipes(int **fd, int n_nodes)
{
	int		i;

	i = 0;
	if (n_nodes > 1)
	{
		while (i < n_nodes)
		{
			close(fd[i][0]);
			close(fd[i][1]);
			free(fd[i]);
			i++;
		}
		free(fd);
	}
}

void	executor(t_node **nodes, int n_nodes)
{
	int		i;
	int		**fd;

	i = 0;
	if (n_nodes > 1)
	{
		fd = ft_calloc(sizeof(int *) * 2, n_nodes - 1);
		while (i < n_nodes)
		{
			fd[i] = malloc (sizeof(int) * 2);
			pipe(fd[i]);
			i++;
		}
	}
	i = 0;
	while (i < n_nodes)
	{
		executor_2(nodes[i], i, fd, n_nodes);
		i++;
	}
	close_pipes(fd, n_nodes);
}
