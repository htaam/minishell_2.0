#include "minishell.h"

void	whileco(char **argu, int pos)
{
	int		sizearg;
	char	*temp;

	sizearg = bdstrcount(argu);
	while (argu[pos])
	{
		if (argu[pos][0] == '$')
		{
			temp = echo(argu[pos]);
			if (temp != NULL)
			{
				printf("%s", temp);
				free(temp);
			}
			else
				printf("%s", argu[pos]);
		}
		else
			printf("%s", argu[pos]);
		if (pos != sizearg)
			printf(" ");
		pos++;
	}
}

void	whileexport(char **argu)
{
	int	i;

	i = 1;
	while (argu[i])
	{
		if (checkpos(argu[i], '=') != ft_strlen(argu[i]))
			export(argu[i]);
		i++;
	}
}

void	whileunset(char **argu)
{
	int	i;

	i = 1;
	while (argu[i])
	{
		if (checkpos(argu[i], '=') == ft_strlen(argu[i]))
			unsent(argu[i]);
		i++;
	}
}

void 	difbuiltt(char **argu)
{
	if (ft_strncmp(argu[0], "pwd", 3) == 0)
	{
		printf("%s\n", my_get_env("PWD"));
	}
	else if (ft_strncmp(argu[0], "env", 3) == 0)
		envb(g_shell.env);
}

void	difbuilt(char **argu)
{

	convertminmai(argu[0], 0);
	if (bdstrcount(argu) > 1)
	{
		if (ft_strncmp(argu[0], "echo", 4) == 0)
		{
			if (ft_strncmp(argu[1], "-n", 2) == 0)
				whileco(argu, 2);
			else
			{
				whileco(argu, 1);
				printf("\n");
			}
		}
		else if (ft_strncmp(argu[0], "export", 6) == 0)
			whileexport(argu);
		else if (ft_strncmp(argu[0], "unset", 5) == 0)
			whileunset(argu);
		else if (ft_strncmp(argu[0], "cd", 2) == 0)
			cd(argu[1]);
	}
	else
		difbuiltt(argu);
}
