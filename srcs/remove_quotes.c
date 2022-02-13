#include "minishell.h"

void	remove_quotes(char	**a)
{
	int		i;
	char	*temp;

	i = 0;
	while (a[i])
	{
		if ((a[i][0]) == '\'')
		{
			temp = ft_substr(a[i], 1, ft_strlen(a[i]) - 2);
			free(a[i]);
			a[i] = temp;
		}
		if ((a[i][0]) == '\"')
		{
			temp = ft_substr(a[i], 1, ft_strlen(a[i]) - 2);
			free(a[i]);
			a[i] = temp;
		}
		i++;
	}
}
