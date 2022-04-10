/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:36:09 by tmatias           #+#    #+#             */
/*   Updated: 2022/04/10 16:59:58 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* global variable declaration */
t_shell	g_shell;

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
	while (line[a])
	{
		if (line[a] != ' ')
			return (0);
		a++;
	}
	return (1);
}

void	do_stuff(char **a)
{
	t_node	**nodes;

	nodes = NULL;
	expander(a);
	remove_quotes(a);
	nodes = parse(a);
	executor(nodes, count_pipes(a) + 1);
	free_nodes(nodes, count_pipes(a));
}

int	main(int argc, char **argv, char **envp)
{
	char			**a;
	char			*line;
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	g_shell.exit = 0;
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
			do_stuff(a);
			ft_freecharmatrix(a);
			free(a);
		}
		free(line);
	}
}
