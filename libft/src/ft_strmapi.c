/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:11:42 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/09 15:31:24 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		a;
	char	*rt;

	a = 0;
	if (s == NULL)
		return (NULL);
	rt = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(rt))
		return (NULL);
	ft_memcpy(rt, s, ft_strlen(s));
	while (rt[a])
	{
		rt[a] = (*f)(a, rt[a]);
		a++;
	}
	rt[ft_strlen(s)] = 0;
	return (rt);
}
