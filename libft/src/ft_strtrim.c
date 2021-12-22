/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:07:26 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/09 14:48:28 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const *set, char s)
{
	int	a;

	a = 0;
	while (a <= ft_strlen(set))
	{
		if (s == (char)set[a])
			return (1);
		a++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		b;
	char	*rt;
	int		len;

	if (!s1)
		return (NULL);
	a = 0;
	while (is_in_set(set, s1[a]))
		a++;
	b = 0;
	while (is_in_set(set, s1[ft_strlen(s1) - b - 1]))
		b++;
	len = ft_strlen(s1) - a - b;
	if (len < 0)
		len = 0;
	rt = malloc(sizeof(char) * (len + 1));
	if (!(rt))
		return (NULL);
	ft_strlcpy(rt, s1 + a, len + 1);
	return (rt);
}
