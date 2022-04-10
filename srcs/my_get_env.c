/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:37:11 by tmatias           #+#    #+#             */
/*   Updated: 2022/04/10 16:37:20 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*my_get_env(char *s)
{
	int		i;
	char	*temp;

	temp = ft_strjoin(s, "=");
	i = 0;
	while (g_shell.env[i])
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

int	my_get_pos(char *s)
{
	int		i;
	char	*temp;

	temp = ft_strjoin(s, "=");
	i = 0;
	while (g_shell.env[i])
	{
		if (ft_strncmp(g_shell.env[i], temp, ft_strlen(temp)) == 0)
		{
			free(temp);
			return (i);
		}
		i++;
	}
	free(temp);
	return (-1);
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
