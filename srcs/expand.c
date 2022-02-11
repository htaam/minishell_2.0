#include "minishell.h"
#include <string.h>

/*static void	add_last_cmd(t_cmd **stack, char *a)
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
		//my ft_strdup must be reviewd
		temp->cmd = ft_strdup(a);
		*stack = temp;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp2 = malloc(sizeof(t_cmd));
		//my ft_strdup must be reviewd
		temp2->cmd = ft_strdup(a);
		temp2->prev = temp;
		temp2->next = NULL;
		temp->next = temp2;
	}
}*/

char	*do_expand(char *list)
{
	char	*new;
	char	*temp;
	char	*new2;

	if (list[0] == '\"')
		list[ft_strlen(list) - 1] = '\0';
	if (list[0] != '\'')
	{
		temp = ft_substr(list, 1 + ft_strchr(list, '$') - list,
				ft_strlen(list));
		if (getenv(temp))
		{
			new = ft_substr(list, 0, ft_strchr(list, '$') - list);
			new2 = ft_strjoin(new, getenv(temp));
		}
		else if (ft_strncmp(temp, "?", 1) == 0)
			new2 = "Must get last command exit status";
		else
			new2 = ft_substr(list, 0, ft_strchr(list, '$') - list);
		if (list[0] == '\"')
			new2 = ft_strjoin(new2, "\"");
		return (new2);
	}
	return (list);
}

void	expander(char	**a)
{
	int			i;

	i = 0;
	while (a[i])
	{
		if (ft_strchr(a[i], '$'))
			a[i] = do_expand(a[i]);
		else
			NULL;
		i++;
	}
}
