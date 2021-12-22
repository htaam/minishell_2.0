/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:29:37 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/10 11:44:45 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (dst[a] && a < dstsize)
		a++;
	while (src[b] && (a + b + 1) < dstsize)
	{
		dst[a + b] = src[b];
		b++;
	}
	if (a < dstsize)
		dst[a + b] = '\0';
	return (a + ft_strlen(src));
}
