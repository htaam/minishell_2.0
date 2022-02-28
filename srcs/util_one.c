#include "minishell.h"

static int	calcds(char **str)
{
	int	i;
	int	j;
	int	l;

	l = 0;
	j = 1;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			l++;
			i++;
		}
	}
	return (l);
}

char	*convertocd(char **str)
{
	int		i;
	int		j;
	int		l;
	char	*path;

	j = 1;
	path = malloc((sizeof(char *) * calcds(str)) + 1);
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			path[l] = str[j][i];
			l++;
			i++;
		}
		j++;
	}
	path[l] = 0;
	return (path);
}
