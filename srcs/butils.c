#include "minishell.h"

int	firstequals(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0')
		return (1);
	return (0);
}

unsigned int	bdstrcount(char **str)
{
	int	j;

	j = 0;
	while (str[j])
		j++;
	return (j);
}

int	clchar(char c, char *str)
{
	int	i;
	int	last;

	i = 0;
	last = -1;
	while (str[i])
	{
		if (str[i] == c)
			last = i;
		i++;
	}
	return (last);
}

int	envpos(char **env, char *path)
{
	int	j;

	j = 0;
	while (env[j])
	{
		if (firstequals(path, env[j]) == ft_strlen(path))
			return (j);
		j++;
	}
	return (-1);
}
