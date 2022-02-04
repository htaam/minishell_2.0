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

static char	*do_expand(char *list)
{
	char	*new;
	char	*temp;

	temp = ft_substr(list, 1 + ft_strchr(list, '$') - list, ft_strlen(list));
	if (getenv(temp))
	{
		new = ft_substr(list, 0, ft_strchr(list, '$') - list);
		ft_strlcat(new, getenv(temp), 99999999999);
	}
	else if (ft_strncmp(temp, "?", 1) == 0)
		new = "Must get last command exit status";
	else
		new = ft_substr(list, 0, ft_strchr(list, '$') - list);
	return (new);
}

void	expander(t_cmd *list, char	**a)
{
	int			i;
	char		*b;

	i = 0;
	while (a[i])
	{
		if (ft_strchr(a[i], '$'))
		{
			b = do_expand(a[i]);
			add_last_cmd(&list, b);
		}
		else
			add_last_cmd(&list, a[i]);
		i++;
	}
}
