#include "minishell.h"

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**cpytd(char ***envv)
{
	char	**env;
	char	**newenv;
	int		j;

	j = 0;
	env = &(**envv);
	newenv = (char **)malloc(sizeof(char *) * (bdstrcount(env) + 1));
	if (newenv == NULL)
		return (0);
	while (env[j])
	{
		newenv[j] = (char *)malloc(sizeof(char) * (ft_strlen(env[j]) + 1));
		ft_strlcpy(newenv[j], env[j], ft_strlen(env[j]) + 1);
		j++;
	}
	newenv[j] = NULL;
	return (newenv);
}

void	extensionofondenv(char **cpy, char *temp, int i, int count)
{
	int	j;

	j = 0;
	while (j < count)
	{
		if (ft_rstrcmp(cpy[i], cpy[j]) >= 0)
		{
			ft_strcpy(temp, cpy[i]);
			ft_strcpy(cpy[i], cpy[j]);
			ft_strcpy(cpy[j], temp);
			i = 0;
			j = 0;
		}
		else
			j++;
	}
}

void	ordenv(char **env)
{
	int		i;
	char	*temp;
	int		count;
	char	**cpy;

	i = 0;
	temp = malloc(1);
	temp[0] = 0;
	cpy = cpytd(&env);
	count = bdstrcount(env);
	while (i < count)
	{
		extensionofondenv(cpy, temp, i, count);
		i++;
	}
	envb(cpy);
	free(cpy);
	free(temp);
}

void	export(char *path)
{
	char	**newenv;
	int		j;

	j = 0;
	newenv = (char **)malloc(sizeof(char *) * (bdstrcount(g_shell.env) + 2));
	if (newenv == NULL)
		exit(0);
	while (g_shell.env[j])
	{
		newenv[j] = malloc(sizeof(char) * (ft_strlen(g_shell.env[j]) + 1));
		ft_strlcpy(newenv[j], g_shell.env[j], ft_strlen(g_shell.env[j]) + 1);
		free(g_shell.env[j]);
		j++;
	}
	newenv[j] = (char *)malloc(sizeof(char) * (ft_strlen(path) + 1));
	ft_strlcpy(newenv[j], path, ft_strlen(path) + 1);
	j++;
	newenv[j] = NULL;
	free(g_shell.env);
	g_shell.env = newenv;
}
