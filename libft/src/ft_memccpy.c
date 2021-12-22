/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:08:46 by tmatias           #+#    #+#             */
/*   Updated: 2021/02/26 18:21:27 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*(char *)dst = *(char *)src;
		if (*(char *)dst == (char)c)
			return (dst + 1);
		dst++;
		src++;
	}
	return (NULL);
}
