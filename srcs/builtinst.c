/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtinst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:34:17 by tmatias           #+#    #+#             */
/*   Updated: 2022/04/10 16:42:38 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (pos < sizearg - 1)
			printf(" ");
		pos++;
	}
}

void	tryexport(char *path)
{
	int		pos;
	char	*novo;

	pos = checkpos(path, '=');
	novo = ft_substr(path, 0, pos);
	if (my_get_env(novo) != NULL)
	{
		unsent(novo);
		export(path);
	}
	else
		export(path);
	free(novo);
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

void	difbuiltt(char **argu)
{
	if (ft_strncmp(argu[0], "pwd", 3) == 0)
	{
		printf("%s\n", my_get_env("PWD"));
	}
	else if (ft_strncmp(argu[0], "env", 3) == 0)
		envb(g_shell.env);
	else if (ft_strncmp(argu[0], "cd", 2) == 0)
		cdv("");
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
			cdv(argu[1]);
	}
	else
		difbuiltt(argu);
}
