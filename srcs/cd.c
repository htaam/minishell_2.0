#include "minishell.h"

void	chpathextension(char *temp, char *tempt, char **temppwd, DIR **pdir)
{
	if (temp[ft_strlen(temp) - 1] == '/')
	{
		free(tempt);
		tempt = ft_substr(temp, 0, ft_strlen(temp) - 1);
		(*pdir = opendir(tempt));
		free((*temppwd));
		(*temppwd) = ft_strdup(tempt);
	}
	else
	{
		(*pdir) = opendir(temp);
		(*temppwd) = ft_strdup(temp);
	}
	free(temp);
	free(tempt);
}

void	chpath(char **temppwd, char **path, DIR **pdir)
{
	char	*temp;
	char	*tempt;

	temp = NULL;
	tempt = NULL;
	while (firstequals((*path), "../") == 3)
	{
		(*path) = ft_substrsc((*path), 3, ft_strlen((*path)));
		if (ft_strcmp("/", (*temppwd)) != 0)
			ft_strlcpy((*temppwd), (*temppwd), clchar('/', (*temppwd)) + 1);
	}
	if (firstequals((*path), ".") == 2)
		(*path) = ft_substrsc((*path), 2, ft_strlen((*path)));
	else if (firstequals((*path), ".") == 1)
		(*path) = ft_substrsc((*path), 1, ft_strlen((*path)));
	if (ft_strcmp("/", (*temppwd)) != 0)
	{
		tempt = ft_strjoin((*temppwd), "/");
		temp = ft_strjoin(tempt, (*path));
		chpathextension(temp, tempt, temppwd, pdir);
	}
	else
		(*pdir) = opendir((*path));
}

void	cdt(char **env, char *path, int oldpwd, int pwdpos)
{
	char	*temppwd;
	char	*initialpath;
	DIR		*pdir;
	char	*temp;

	temp = NULL;
	pdir = NULL;
	temppwd = NULL;
	initialpath = ft_strdup(path);
	ft_strcpy(temppwd, my_get_env("PWD="));
	chpath(&temppwd, &path, &pdir);
	if (!pdir)
		cdf(env, initialpath, oldpwd, pwdpos);
	else
	{
		temp = echo("PWD=");
		free(env[oldpwd]);
		env[oldpwd] = ft_strjoin("OLDPWD=", temp);
		free(env[pwdpos]);
		env[pwdpos] = ft_strjoin("PWD=", temppwd);
		closedir(pdir);
		free(temp);
	}
	free(initialpath);
	free(temppwd);
}

void	cdextension(char **env, char *temp, int pwdpos, int oldpwdpos)
{
	ft_strcpy(temp, my_get_env("PWD="));
	free(env[oldpwdpos]);
	env[oldpwdpos] = ft_strjoin("OLDPWD=", temp);
	free(temp);
	ft_strcpy(temp, my_get_env("HOME="));
	free(env[pwdpos]);
	env[pwdpos] = ft_strjoin("PWD=", temp);
	free(temp);
}

void	cd(char *path)
{
	int		pwdpos;
	int		oldpwdpos;
	int		homepos;
	char	*temp;

	homepos = envpos(g_shell.env, "HOME=");
	pwdpos = envpos(g_shell.env, "PWD=");
	oldpwdpos = envpos(g_shell.env, "OLDPWD=");
	temp = NULL;
	if (ft_strcmp("..", path) == 0)
	{
		if (ft_strcmp(g_shell.env[pwdpos], g_shell.env[homepos]) != 0)
		{
			ft_strcpy(temp, my_get_env("PWD="));
			free(g_shell.env[oldpwdpos]);
			g_shell.env[oldpwdpos] = ft_strjoin("OLDPWD=", temp);
			free(temp);
			ft_strlcpy(g_shell.env[pwdpos], g_shell.env[pwdpos],
			clchar('/', g_shell.env[pwdpos]) + 1);
		}
	}
	else if (ft_strlen(path) == 0 || path == NULL)
		cdextension(g_shell.env, temp, pwdpos, oldpwdpos);
	else
		cdt(g_shell.env, path, oldpwdpos, pwdpos);
}
