#include "minishell.h"

void	do_expland_aux(char	**str)
{
	char	*temp;

	temp = ft_strjoin(*str, "\"");
	free(*str);
	*str = ft_strdup(temp);
	free(temp);
}

char	*do_expand(char *list)
{
	char	*new;
	char	*temp;
	char	*new2;

	if (list[0] == '\"')
		list[ft_strlen(list) - 1] = '\0';
	temp = ft_substr(list, 1 + ft_strchr(list, '$') - list,
			ft_strlen(list));
	if (getenv(temp))
	{
		new = ft_substr(list, 0, ft_strchr(list, '$') - list);
		new2 = ft_strjoin(new, getenv(temp));
		free(new);
	}
	else if (ft_strncmp(temp, "?", 1) == 0)
		new2 = "Must get last command exit status";
	else
		new2 = ft_substr(list, 0, ft_strchr(list, '$') - list);
	if (list[0] == '\"')
	{
		do_expland_aux(&new2);
	}
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
