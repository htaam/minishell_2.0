/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:24 by tmatias           #+#    #+#             */
/*   Updated: 2022/04/10 16:55:48 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test_relative_paths(char *cmd, char **args)
{
	char	*temp;
	char	*new_path;
	int		aux;

	temp = my_get_env("PWD");
	new_path = ft_strjoin(temp, cmd + 1);
	execve(new_path, args, g_shell.env);
	free(new_path);
	temp = my_get_env("PWD");
	new_path = ft_strjoin(temp, cmd);
	execve(new_path, args, g_shell.env);
	ft_putstr_fd("Command not found:\t", 2);
	ft_putstr_fd(args[0], 2);
	ft_putstr_fd("\n", 2);
	free(new_path);
	aux = 127;
	write (g_shell.exit_pipe[1], &aux, sizeof(aux));
	close (g_shell.exit_pipe[1]);
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

void	child_stuff(int *info, char *cmd, char **arg, int **fd)
{
	int	aux;

	signal(SIGQUIT, sig_handle2);
	close_extra_pipes(fd, info[0], info[1]);
	close (g_shell.exit_pipe[0]);
	if (cmd[0] == '/')
	{
		if (execve(cmd, arg, g_shell.env) == -1)
		{
			aux = 127;
			write (g_shell.exit_pipe[1], &aux, sizeof(aux));
			close (g_shell.exit_pipe[1]);
			printf("Invalid command address.\n");
			exit(0);
		}
	}
	else
	{
		ft_exec(cmd, arg);
		exit(0);
	}
}

void	do_exeve(char	*cmd, char	**arg, int **fd, int *info)
{
	pid_t	pid;
	pid_t	test;

	pipe(g_shell.exit_pipe);
	pid = fork();
	if (pid == 0)
	{
		child_stuff(info, cmd, arg, fd);
	}
	else
	{
		close (g_shell.exit_pipe[1]);
		waitpid(pid, &test, 0);
		if (test != 0)
			g_shell.exit_status = 1;
		else
			read(g_shell.exit_pipe[0], &g_shell.exit_status,
				sizeof(g_shell.exit_status));
		close (g_shell.exit_pipe[1]);
	}
}
