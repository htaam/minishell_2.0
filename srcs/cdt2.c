/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdt2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:50:24 by tmatias           #+#    #+#             */
/*   Updated: 2022/04/10 16:50:37 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
