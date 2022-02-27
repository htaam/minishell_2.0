#include "minishell.h"

/* global variable declaration */
t_shell	g_shell;

static void	env_error(int error)
{
	if (error == 0)
		ft_putendl_fd("Unable to create environment", 1);
	else if (error == 1)
	{
		ft_putendl_fd("Unable to create environment variables", 1);
		while (*g_shell.env)
		{
			free(*g_shell.env);
			g_shell.env++;
		}
		free (*g_shell.env);
		free (g_shell.env);
	}
	exit(0);
}

void	init_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	g_shell.env = malloc(sizeof(char *) * i + 1);
	if (!g_shell.env)
		env_error(0);
	*g_shell.env = NULL;
	i = 0;
	while (envp[i])
	{
		g_shell.env[i] = ft_strdup(envp[i]);
		if (!g_shell.env[i])
			env_error(1);
		i++;
	}
	g_shell.env[i] = NULL;
}

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

	g_shell.exit = 0;
	nodes = NULL;
	(void)argc;
	(void)argv;
	init_env(envp);
	while (g_shell.exit == 0)
	{
		line = 0;
		line = rl_w_history("Prompt minishell$ ", line);
		a = ft_cmdtrim(line, " ");
		a = ft_subsplit(a);
		expander(a);
		remove_quotes(a);
		nodes = parse(a);
		n_nodes = count_pipes(a) + 1;
		executor(nodes, n_nodes);
		free_nodes(nodes, count_pipes(a));
		ft_freecharmatrix(a);
		free(a);
		free(line);
	}
	return (0);
}
