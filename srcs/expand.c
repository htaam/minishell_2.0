#include "minishell.h"

static void	add_last_cmd(t_cmd **stack, char *a)
{
	t_cmd		*temp;
	static int	first = 1;
	t_cmd		*temp2;

	temp = *stack;
	printf("\n a-> %s\n", a);
	if (first)
	{
		first = 0;
		temp->next = NULL;
		temp->prev = NULL;
		printf("\n a-> %s\n", a);
		temp->cmd = ft_strdup("");
		ft_strlcat(temp->cmd, a, ft_strlen(temp->cmd) + ft_strlen(a) + 1);
		*stack = temp;
		printf("\n cmd-> %s\n", temp->cmd);
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp2 = malloc(sizeof(t_cmd));
		temp2->cmd = ft_strdup(a);
		temp2->prev = temp;
		temp2->next = NULL;
		temp->next = temp2;
		printf("\n cmd-> %s\n", temp2->cmd);
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
		printf("\nnew -> %s\n", new);
		printf("\ngetenv -> %s\n", getenv(temp));
		ft_strlcat(new, getenv(temp), ft_strlen(new) + 1 + ft_strlen(getenv(temp)));
	}
	else if (ft_strncmp(temp, "?", 1) == 0)
		new = "Must get last command exit status";
	else
		new = ft_substr(list, 0, ft_strchr(list, '$') - list);
	printf("\nlcat -> %s\n\n", new);
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
			printf("\nb -> %s\n\n", b);
			add_last_cmd(&list, b);
		}
		else
			add_last_cmd(&list, a[i]);
		i++;
	}
}
