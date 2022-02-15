#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		**a;
	int			i;
	char		*line;
	t_node		*nodes;
	int			j;

	nodes = NULL;
	(void)argc;
	(void)argv;
	(void)envp;
	line = 0;
	i = 0;
	line = rl_w_history("minishell$ ", line);
	if (ft_strncmp("exit", line, 5) == 0)
		exit (0);
	a = ft_cmdtrim(line, " ");
	a = ft_subsplit(a);
	expander(a);
	remove_quotes(a);
	while (a[i])
	{
		printf("%s\n", a[i]);
		i++;
	}
	nodes = parse(a);
	i = 0;
	while (nodes[i].in_file == 1)
	{
		j = 0;
		printf("nodes[%d]\nCMD = %s\n", i, nodes[i].cmd);
		while (nodes[i].arg[j])
		{
			printf("arg[%d] = %s\n", j, nodes[i].arg[j]);
			j++;
		}
		i++;
	}
	ft_freecharmatrix(a);
	free(a);
	free(line);
	return (0);
}
