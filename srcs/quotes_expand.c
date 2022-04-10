/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:37:29 by tmatias           #+#    #+#             */
/*   Updated: 2022/04/10 16:37:42 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_expand_aux(char	**str)
{
	char	*temp;

	temp = ft_strjoin(*str, "\"");
	free(*str);
	*str = ft_strdup(temp);
	free(temp);
}

char	*do_expand2(char *list)
{
	char	*new;
	char	*temp;
	char	*new2;

	temp = ft_substr(list, 1 + ft_strchr(list, '$') - list,
			ft_strlen(list));
	if (my_get_env(temp))
	{
		new = ft_substr(list, 0, ft_strchr(list, '$') - list);
		new2 = ft_strjoin(new, my_get_env(temp));
		free(new);
	}
	else if (ft_strncmp(temp, "?", 1) == 0)
		new2 = do_expand_aux_2(list);
	else
		new2 = ft_substr(list, 0, ft_strchr(list, '$') - list);
	free(temp);
	return (new2);
}

char	*reform_str(char	**a)
{
	char	*str;
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	str = ft_strdup(a[i]);
	free(a[i]);
	while (a[++i])
	{
		temp = ft_strjoin(str, " ");
		temp2 = ft_strjoin(temp, a[i]);
		free(temp);
		free(str);
		str = ft_strdup(temp2);
		free(temp2);
		free(a[i]);
	}
	free(a);
	str[ft_strlen(str)] = '"';
	str[ft_strlen(str)] = '\0';
	return (str);
}

char	*do_quotes_expand(char *list)
{
	char	**a;
	int		i;
	char	*temp;

	list[ft_strlen(list) - 1] = '\0';
	i = 0;
	a = ft_split(list, ' ');
	while (a[i])
	{
		if (ft_strchr(a[i], '$'))
		{
			temp = do_expand2(a[i]);
			free(a[i]);
			a[i] = ft_strdup(temp);
			free(temp);
		}
		else
			NULL;
		i++;
	}
	return (reform_str(a));
}
