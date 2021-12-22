/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:44:46 by tmatias           #+#    #+#             */
/*   Updated: 2021/04/05 16:44:50 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

unsigned long long int	ft_abs(long long int d)
{
	if (d >= 0)
		return ((unsigned long long int)d);
	else if (d != LONG_MIN)
		return ((unsigned long long int)d * (-1));
	else
		return (((unsigned long long int)(LLONG_MAX) + 1));
}
