/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:35:20 by tmatias           #+#    #+#             */
/*   Updated: 2022/04/10 16:35:24 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_error(int error)
{
	if (error == 0)
		ft_putendl_fd("Unable to create environment", 1);
	else if (error == 1)
	{
		ft_putendl_fd("Unable to create environment variables", 1);
		while (*g_shell.env)
		{
			free(*g_shell.env);
			g_shell.env++;
		}
		free (*g_shell.env);
		free (g_shell.env);
	}
	exit(0);
}

void	increase_shell_lvl(void)
{
	int		i;
	char	*new_char;
	int		new_int;

	i = 0;
	while (g_shell.env[i])
	{
		if (ft_strncmp(g_shell.env[i], "SHLVL=", 6) == 0)
		{
			new_int = ft_atoi(&g_shell.env[i][6]);
			new_char = ft_itoa(new_int + 1);
			free(g_shell.env[i]);
			g_shell.env[i] = ft_strjoin("SHLVL=", new_char);
			free(new_char);
		}
		i++;
	}
}

void	init_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	g_shell.env = malloc(sizeof(char *) * (i + 1));
	if (!g_shell.env)
		env_error(0);
	*g_shell.env = NULL;
	i = 0;
	while (envp[i])
	{
		g_shell.env[i] = ft_strdup(envp[i]);
		if (!g_shell.env[i])
			env_error(1);
		i++;
	}
	g_shell.env[i] = NULL;
	increase_shell_lvl();
}
