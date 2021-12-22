/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:36:59 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/08 15:40:14 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*rt;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	rt = malloc(sizeof(char) * (len + 1));
	if (!(rt))
		return (NULL);
	ft_memcpy(rt, s1, ft_strlen(s1));
	ft_memcpy(rt + ft_strlen(s1), s2, ft_strlen(s2));
	rt[len] = 0;
	return (rt);
}
