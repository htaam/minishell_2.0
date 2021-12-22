/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:27:13 by tmatias           #+#    #+#             */
/*   Updated: 2021/02/26 18:34:52 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *c1, const char *c2, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char *)c1;
	s2 = (char *)c2;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (*s1 != *s2++)
		{
			return (*(unsigned char *)s1 - *(unsigned char *)(s2 - 1));
		}
		if (*s1++ == 0)
			break ;
		n--;
	}
	return (0);
}
