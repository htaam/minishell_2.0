/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:50:38 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/08 16:57:30 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (!(ptr_dst) && !(ptr_src) && len > 0)
		return (dst);
	if (src < dst)
	{
		while (len--)
		{
			ptr_dst[len] = ptr_src[len];
		}
	}
	else
	{
		while (len--)
		{
			*ptr_dst++ = *ptr_src++;
		}
	}
	return (dst);
}
