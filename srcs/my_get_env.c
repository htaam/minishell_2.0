#include "minishell.h"

char	*my_get_env(char *s)
{
	int		i;
	char	*temp;

	temp = ft_strjoin(s, "=");
	i = 0;
	while(g_shell.env[i])
	{
		if (ft_strncmp(g_shell.env[i], temp, ft_strlen(temp)) == 0)
		{
			free(temp);
			return (g_shell.env[i] + ft_strlen(s) + 1);
		}
		i++;
	}
	free(temp);
	return (NULL);
}