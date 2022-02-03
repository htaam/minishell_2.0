#include "minishell.h"

static void	add_last_cmd(t_cmd **stack, char *a)
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

static void	do_expand(t_cmd *list)
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
		new = "Must get last command exit status";
		list->cmd = new;
	}
	else
		new = "";
		list->cmd = new;
}

static void	expander2(t_cmd *list)
{
	while (list)
	{
		if (ft_strchr((list)->cmd, '$'))
			do_expand(list);
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
