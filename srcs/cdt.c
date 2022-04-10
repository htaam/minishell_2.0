/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:33:22 by tmatias           #+#    #+#             */
/*   Updated: 2022/04/10 16:52:11 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substrsc(char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*cpy;

	if (!s)
		return (s);
	cpy = s;
	if (len >= (size_t)(ft_strlen(s) - (int)start))
		len = lencalc(s, (int)start);
	if ((int)start >= ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		free(cpy);
		return (str);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	ft_strlcpy(str, cpy + start, len + 1);
	free(cpy);
	free(str);
	return (str);
}

void	cdf(char **env, char *initialpath, int oldpwd, int pwdpos)
{
	char	*tempwd;
	DIR		*pdir;

	tempwd = ft_strdup(my_get_env("PWD"));
	pdir = opendir(initialpath);
	if (!pdir)
		printf("Cannot open directory '%s'\n", initialpath);
	else
	{
		free(env[oldpwd]);
		env[oldpwd] = ft_strjoin("OLDPWD=", tempwd);
		free(env[pwdpos]);
		if (initialpath[ft_strlen(initialpath) - 1] == '/')
		{
			free(tempwd);
			tempwd = ft_substr(initialpath, 0, ft_strlen(initialpath) - 1);
			env[pwdpos] = ft_strjoin("PWD=", tempwd);
		}
		else
			env[pwdpos] = ft_strjoin("PWD=", initialpath);
		closedir(pdir);
	}
	free(tempwd);
}

void	cdeasyversion_aux(char *tempwd, char *teste, char *path)
{
	int	pwd;
	int	oldpwd;

	pwd = my_get_pos("PWD");
	oldpwd = my_get_pos("OLDPWD");
	if (ft_strcmp(tempwd, teste) != 0)
	{
		free(g_shell.env[oldpwd]);
		g_shell.env[oldpwd] = ft_strjoin("OLDPWD=", tempwd);
		free(g_shell.env[pwd]);
		g_shell.env[pwd] = ft_strjoin("PWD=", teste);
	}
	else if (ft_strcmp(path, "/.") != 0)
	{
		printf("cd: no such file or directory: %s\n", path);
		g_shell.exit_status = 1;
	}
}

void	cdeasyversion(char *path, bool haveb)
{
	char	*tempwd;
	char	*teste;
	char	*temporary;

	teste = NULL;
	tempwd = ft_strdup(my_get_env("PWD"));
	if (haveb == true)
	{
		temporary = ft_strjoin(tempwd, path);
		chdir(temporary);
		free(temporary);
	}
	else
		chdir(path);
	teste = malloc(sizeof(char) * 501);
	getcwd(teste, 500);
	teste[500] = 0;
	cdeasyversion_aux(tempwd, teste, path);
	free(tempwd);
	free(teste);
}

void	cdv(char *path)
{
	char	*temp;
	int		pwd;
	int		oldpwd;
	bool	relative;

	temp = NULL;
	relative = false;
	pwd = my_get_pos("PWD");
	oldpwd = my_get_pos("OLDPWD");
	if (path[0] != '/' && ft_strcmp(path, "") != 0)
	{
		temp = ft_strjoin("/", path);
		relative = true;
	}
	if (ft_strcmp(path, "") == 0)
		temp = ft_strdup(my_get_env("HOME"));
	if (temp != NULL)
		cdeasyversion(temp, relative);
	else
		cdeasyversion(path, relative);
	if (relative == true || ft_strcmp(path, "") == 0)
		free(temp);
}
