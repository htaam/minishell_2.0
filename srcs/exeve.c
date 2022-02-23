#include "minishell.h"

void	ft_testpaths(char *cmd, char **args, char **paths)
{
	int		i;
	char	*temp;
	char	*newpath;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		newpath = ft_strjoin(temp, cmd);
		execve(newpath, args, g_shell.env);
		free(newpath);
		free(temp);
		i++;
	}
	ft_freecharmatrix(paths);
	printf("No such command found.");
}

void	ft_exec(char *cmd, char **args)
{
	int		i;
	char	**paths;

	paths = NULL;
	i = 0;
	while (g_shell.env[i])
	{
		if (ft_strncmp(g_shell.env[i], "PATH", 4) == 0)
		{
			g_shell.env[i] += 5;
			paths = ft_split(g_shell.env[i], ':');
			break ;
		}
		i++;
	}
	ft_testpaths(cmd, args, paths);
}

void	do_exeve(char	*cmd, char	**arg)
{
	if (cmd[0] == '/')
	{
		if (execve(cmd, arg, g_shell.env) == -1)
			printf("Invalid command address.");
	}
	else
		ft_exec(cmd, arg);
}
