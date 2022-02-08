#include "minishell.h"

void	print_solution_values(t_cmd *solution)
{
	while (solution)
	{
		ft_putstr_fd(solution->cmd, 1);
		ft_putstr_fd("\n", 1);
		solution = solution->next;
	}
}

void	ft_clear_cmd(t_cmd **stack)
{
	t_cmd	*temp;

	temp = *stack;
	while (temp)
	{
		(*stack) = temp;
		temp = (*stack)->next;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		(*stack)->cmd = NULL;
		if (*stack)
			free (*stack);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char		**a;
	int			i;
	char		*line;
	t_cmd		*cmd_list;

	(void)argc;
	(void)argv;
	(void)envp;
	line = 0;
	i = -1;
	line = rl_w_history("minishell$ ", line);
	if (ft_strncmp("exit", line, 5) == 0)
		exit (0);
	a = ft_cmdtrim(line, " ");
	cmd_list = malloc(sizeof(t_cmd));
	expander(cmd_list, a);
	print_solution_values(cmd_list);
	//ft_clear_cmd(&cmd_list);
	//ft_freecharmatrix(a);
	//free(a);
	//free(line);
	return (0);
}
