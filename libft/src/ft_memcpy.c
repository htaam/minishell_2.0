/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:59:45 by tmatias           #+#    #+#             */
/*   Updated: 2021/02/26 18:20:28 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*my_src;
	char	*my_dst;
	size_t	i;

	my_src = (char *)src;
	my_dst = (char *)dst;
	i = 0;
	if (!(my_src) && !(my_dst) && n > 0)
		return (dst);
	while (i < n)
	{
		my_dst[i] = my_src[i];
		i++;
	}
	return (dst);
}
