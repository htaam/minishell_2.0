/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:41:01 by tmatias           #+#    #+#             */
/*   Updated: 2021/02/26 18:10:14 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		result;
	int		signal;
	char	*ptr;

	result = 0;
	signal = 1;
	ptr = (char *)str;
	while ((*ptr == 32 || *ptr == '\t' || *ptr == '\v'
			|| *ptr == '\f' || *ptr == '\r' || *ptr == '\n') && ptr != 0)
	{
		ptr++;
	}
	if (!(*ptr))
		return (0);
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr++ == '-')
			signal = -1;
	}
	while (ft_isdigit(*ptr))
	{
		result = result * 10 + (*ptr - 48);
		ptr++;
	}
	return (signal * result);
}
