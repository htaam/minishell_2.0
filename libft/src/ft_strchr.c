/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:06:06 by tmatias           #+#    #+#             */
/*   Updated: 2021/02/26 18:27:26 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	int		a;
	char	*d;

	a = 0;
	d = (char *)s;
	while (*(d + a))
	{
		if (*(d + a) == (char)c)
			return (d + a);
		a++;
	}
	if (c == 0)
		return (d + a);
	return (NULL);
}
