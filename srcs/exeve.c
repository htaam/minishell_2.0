#include "minishell.h"

void	test_relative_paths(char *cmd, char **args)
{
	char	*temp;
	char	*new_path;

	temp = my_get_env("PWD");
	new_path = ft_strjoin(temp, cmd + 1);
	execve(new_path, args, g_shell.env);
	free(new_path);
	temp = my_get_env("PWD");
	new_path = ft_strjoin(temp, cmd);
	execve(new_path, args, g_shell.env);
	ft_putstr_fd("Command not found\n", 1);
	free(new_path);	
	g_shell.exit_status = 1;
}

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
		free(temp);
		execve(newpath, args, g_shell.env);
		free(newpath);
		i++;
	}
	ft_free_matrix(&paths);
	test_relative_paths(cmd, args);
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
			g_shell.env[i] -= 5;
			break ;
		}
		i++;
	}
	ft_testpaths(cmd, args, paths);
}

void	close_extra_pipes(int **fd, int i, int n_nodes)
{
	int	j;

	j = 0;
	if (n_nodes > 1)
	{
		while (j < n_nodes)
		{
			if (j == i)
				;
			else if (j == i - 1)
				close(fd[j][1]);
			else
			{
				close(fd[j][1]);
				close(fd[j][0]);
			}
		j++;
		}
	}
}

void	do_exeve(char	*cmd, char	**arg, int **fd, int *info)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		close_extra_pipes(fd, info[0], info[1]);
		if (cmd[0] == '/')
		{
			if (execve(cmd, arg, g_shell.env) == -1)
				printf("Invalid command address.");
		}
		else
		{
			ft_exec(cmd, arg);
			exit(0);
		}
	}
	else
		wait(NULL);
}
