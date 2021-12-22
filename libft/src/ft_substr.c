/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:36:02 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/09 14:53:10 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (len >= (size_t)(ft_strlen(s) - (int)start))
	{
		len = ft_strlen(s) - (int)start;
		if (len < 0)
			len = 0;
	}
	if ((int)start >= ft_strlen(s))
	{
		str = malloc(sizeof(char));
		str[0] = 0;
		return (str);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
