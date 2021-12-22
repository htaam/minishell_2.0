/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:40:34 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/10 11:45:20 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t		n;
	int			i;

	i = 0;
	n = siz;
	if (!src)
		return (0);
	if (n != 0)
	{
		while (--n != 0)
		{
			dst[i] = src[i];
			if ((dst[i++]) == 0)
				break ;
		}
	}
	if (n == 0)
	{
		if (siz != 0)
			dst[i] = 0;
		while (src[i++])
			;
	}
	return (&src[i] - src - 1);
}
