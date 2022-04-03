#include "minishell.h"

int	ft_rstrcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	lencalc(char *s, int start)
{
	int	len;

	len = ft_strlen(s) - start;
	if (len < 0)
		len = 0;
	return (len);
}

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
		str[0] = 0;
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

	tempwd = NULL;
	ft_strcpy(tempwd, my_get_env("PWD="));
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
