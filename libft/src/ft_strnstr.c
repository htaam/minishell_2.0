/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:23:06 by tmatias           #+#    #+#             */
/*   Updated: 2021/02/27 14:50:07 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	if (!(*needle))
		return ((char *)haystack);
	a = -1;
	b = 0;
	while (haystack[++a] && a + b <= len && (!(len <= 0)
			|| (ft_strlen(needle) >= ft_strlen(haystack))))
	{
		b = -1;
		while (++b + 1 && needle[b] == haystack[a + b] && a + b <= len)
		{
			if (a + b >= len)
				break ;
			if (needle[b + 1] == 0 && a + b <= len)
				return ((char *)haystack + a);
		}
		if (a + b >= len)
			break ;
	}
	return (NULL);
}
