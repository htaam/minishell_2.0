/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:15:49 by tmatias           #+#    #+#             */
/*   Updated: 2021/02/27 13:40:46 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*d;
	int		a;
	char	*b;

	b = NULL;
	d = (char *)s;
	a = 0;
	while (*d)
	{
		if (ft_strchr(d, c))
			b = ft_strchr(d, c);
		d++;
	}
	if (c == 0)
		return (ft_strchr(d, c));
	if (b != 0)
		return (b);
	return (NULL);
}
