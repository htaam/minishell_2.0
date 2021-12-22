/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:11:56 by tmatias           #+#    #+#             */
/*   Updated: 2021/04/06 14:11:58 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"

static int	count_num(unsigned long long int n, char *base)
{
	long long int	a;

	a = 1;
	while (n / (ft_strlen(base)))
	{
		n = (n / (ft_strlen(base)));
		a++;
	}
	return (a);
}

static char	convert_char(unsigned long long int n, char *base)
{
	return (base[n]);
}

static void	create_result(long long int a, unsigned long long int n
						, char *result, char *base)
{
	long long int	b;

	b = a - 1;
	while (b > -1)
	{
		result[b] = convert_char(n % ft_strlen(base), base);
		n = n / ft_strlen(base);
		b--;
	}
	result[a] = 0;
}

char	*ft_itoa_base_unsigned(unsigned long long int n, char *base)
{
	char				*result;
	long long int		a;

	a = count_num(n, base);
	result = malloc(sizeof(char) * (a + 1));
	if (!(result))
		return (NULL);
	create_result(a, n, result, base);
	return (result);
}
