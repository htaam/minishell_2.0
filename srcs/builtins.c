/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:34:07 by tmatias           #+#    #+#             */
/*   Updated: 2022/04/10 16:40:57 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unsentext(char *env, char **newenv, char *path, int *i)
{
	if (((ft_strchr(env, '=') - env) == (ft_strlen(path))))
	{
		if (ft_strncmp(env, path, ft_strlen(path)) != 0)
		{
			newenv[*i] = (char *)malloc(sizeof(char) * (ft_strlen(env) + 1));
			ft_strlcpy(newenv[*i], env, ft_strlen(env) + 1);
			(*i)++;
		}
	}
	else
	{
		newenv[*i] = (char *)malloc(sizeof(char) * (ft_strlen(env) + 1));
		ft_strlcpy(newenv[*i], env, ft_strlen(env) + 1);
		(*i)++;
	}
}

void	unsent(char *path)
{
	char	**newenv;
	int		j;
	int		i;

	i = 0;
	j = 0;
	newenv = (char **)malloc(sizeof(char *) * (bdstrcount(g_shell.env)));
	if (newenv == NULL)
		exit(0);
	while (g_shell.env[j])
	{
		unsentext(g_shell.env[j], newenv, path, &i);
		free(g_shell.env[j]);
		j++;
	}
	newenv[bdstrcount(g_shell.env) - 1] = NULL;
	free(g_shell.env);
	g_shell.env = newenv;
}

void	envb(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		printf("%s\n", env[i]);
	}
}

char	*echo(char *path)
{
	int		i;
	int		pathlen;
	char	*save;

	i = 0;
	save = malloc(1);
	save[0] = '\0';
	pathlen = ft_strlen(path);
	while (g_shell.env[i])
	{
		if (firstequals(g_shell.env[i], path) == ft_strlen(path))
			ft_strlcpy(save, g_shell.env[i] + pathlen,
				ft_strlen(g_shell.env[i]) - pathlen + 1);
		i++;
	}
	if (ft_strlen(save) > 0)
		return (save);
	else
		free(save);
	return (NULL);
}

int	checkpos(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}
