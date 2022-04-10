/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:34:41 by tmatias           #+#    #+#             */
/*   Updated: 2022/04/10 16:41:59 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	firstequals(char *s1, char *s2)
{
	int	i;
	int	s1s;
	int	s2s;

	i = 0;
	s1s = ft_strlen(s1);
	s2s = ft_strlen(s2);
	while (s1[i] == s2[i] && i < s1s && i < s2s)
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

int	envpos(char *path)
{
	int	j;

	j = 0;
	while (g_shell.env[j])
	{
		if (firstequals(path, g_shell.env[j]) == ft_strlen(path))
			return (j);
		j++;
	}
	return (-1);
}
