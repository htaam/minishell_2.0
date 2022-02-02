#include "minishell.h"

static int	ft_count_words(const char *s, char *c, int i[2])
{
	int		q[2];

	q[0] = 0;
	q[1] = 0;
	while (s[i[0]] != '\0')
	{
		if (!ft_strchr(c, s[i[0]]))
		{
			i[1]++;
			while ((!ft_strchr(c, s[i[0]]) || q[0]) && s[i[0]] != '\0')
			{
				if (!q[1] && (s[i[0]] == '\"' || s[i[0]] == '\''))
					q[1] = s[i[0]];
				q[0] = (q[0] + (s[i[0]] == q[1])) % 2;
				q[1] *= q[0] != 0;
				i[0]++;
			}
			if (q[0])
				return (-1);
		}
		else
			i[0]++;
	}
	return (i[1]);
}

static char	**ft_fill_array(char **aux, char const *s, char *set, int i[3])
{
	int		s_len;
	int		q[2];

	q[0] = 0;
	q[1] = 0;
	s_len = ft_strlen(s);
	while (s[i[0]])
	{
		while (ft_strchr(set, s[i[0]]) && s[i[0]] != '\0')
			i[0]++;
		i[1] = i[0];
		while ((!ft_strchr(set, s[i[0]]) || q[0] || q[1]) && s[i[0]])
		{
			q[0] = (q[0] + (!q[1] && s[i[0]] == '\'')) % 2;
			q[1] = (q[1] + (!q[0] && s[i[0]] == '\"')) % 2;
			i[0]++;
		}
		if (i[1] >= s_len)
			aux[i[2]++] = "\0";
		else
			aux[i[2]++] = ft_substr(s, i[1], i[0] - i[1]);
	}
	return (aux);
}

char	**ft_cmdtrim(char const *s, char *set)
{
	char	**aux;
	int		nwords;
	int		i[3];
	int		counts[2];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	counts[0] = 0;
	counts[1] = 0;
	if (!s)
		return (NULL);
	nwords = ft_count_words(s, set, counts);
	if (nwords == -1)
		return (NULL);
	aux = malloc((nwords + 1) * sizeof(char *));
	if (aux == NULL)
		return (NULL);
	aux = ft_fill_array(aux, s, set, i);
	aux[nwords] = NULL;
	return (aux);
}

void	add_last_cmd(t_cmd **stack, char *a)
{
	t_cmd		*temp;
	static int	first = 1;
	t_cmd		*temp2;

	temp = *stack;
	if (first)
	{
		first = 0;
		temp->next = NULL;
		temp->prev = NULL;
		temp->cmd = a;
		*stack = temp;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp2 = malloc(sizeof(t_cmd));
		temp2->cmd = a;
		temp2->prev = temp;
		temp2->next = NULL;
		temp->next = temp2;
	}
}

void	do_expand(t_cmd *list)
{
	char	*new;
	char	*temp;

	temp = ft_substr(list->cmd, 1, ft_strlen(list->cmd) - 1);
	if (getenv(temp))
	{
		new = getenv(temp);
		list->cmd = new;
	}
	else if (ft_strncmp(temp, "?", 1) == 0)
	{
		ft_putstr_fd("DO $?\n", 1);
	}
	else
		ft_putstr_fd("INVALID ENV VARIABLE\n", 1);
}

void	expander2(t_cmd *list)
{
	while (list)
	{
		if (ft_strchr((list)->cmd, '$'))
		{
			do_expand(list);
		}
		list = (list)->next;
	}
}

void	expander(t_cmd *list, char	**a)
{
	int			i;

	i = 0;
	while (a[i])
	{
		add_last_cmd(&list, a[i]);
		i++;
	}
	expander2(list);

}

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
	ft_clear_cmd(&cmd_list);
	ft_freecharmatrix(a);
	free(a);
	free(line);
	return (0);
}
