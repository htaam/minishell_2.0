#include "minishell.h"

char	*do_expand_aux_2(char *list)
{
	char	*temp;
	char	*new;

	temp = ft_substr(list, 0, ft_strchr(list, '$') - list);
	new = ft_strjoin(temp, ft_itoa(g_shell.exit_status));
	free(temp);
	return (new);
}


char	*do_expand(char *list)
{
	char	*new;
	char	*temp;
	char	*new2;

	if (list[0] == '\"')
		return (do_quotes_expand(list));
	temp = ft_substr(list, 1 + ft_strchr(list, '$') - list,
			ft_strlen(list));
	if (getenv(temp))
	{
		new = ft_substr(list, 0, ft_strchr(list, '$') - list);
		new2 = ft_strjoin(new, getenv(temp));
		free(new);
	}
	else if (ft_strncmp(temp, "?", 1) == 0)
		new2 = do_expand_aux_2(list);
	else
		new2 = ft_substr(list, 0, ft_strchr(list, '$') - list);
	free(temp);
	return (new2);
}

void	expander(char	**a)
{
	int			i;
	char		*temp;

	i = 0;
	while (a[i])
	{
		if (ft_strchr(a[i], '$'))
		{
			if (a[i][0] != '\'')
			{
				temp = do_expand(a[i]);
				free(a[i]);
				a[i] = ft_strdup(temp);
				free(temp);
			}
		}
		else
			NULL;
		i++;
	}
}
