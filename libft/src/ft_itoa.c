/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:40:40 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/09 15:10:34 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num(long long int n)
{
	long long int	a;

	a = 1;
	while (n / 10)
	{
		n = (n / 10);
		a++;
	}
	return (a);
}

static char	convert_char(long long int n)
{
	return ('0' + n);
}

static void	create_result(long long int a, long long int n,
							long long int min_int, char *result)
{
	long long int	b;
	long long int	is_nega;

	is_nega = 0;
	if (n < 0)
	{
		is_nega = 1;
		result[0] = '-';
		n = n * (-1);
	}
	b = a - 1;
	while (b > -1)
	{
		result[b] = convert_char(n % 10);
		if (min_int == 1 && b == 10)
			result[b] = convert_char(8);
		n = n / 10;
		b--;
		if (b == 0 && is_nega == 1)
			break ;
	}
	result[a] = 0;
}

char	*ft_itoa(long long int n)
{
	char				*result;
	long long int		a;
	long long int		min_int;

	min_int = 0;
	if (n == -2147483648)
	{
		min_int = 1;
		n++;
	}
	a = count_num(n);
	if (n < 0)
		a++;
	result = malloc(sizeof(char) * (a + 1));
	if (!(result))
		return (NULL);
	create_result(a, n, min_int, result);
	return (result);
}
