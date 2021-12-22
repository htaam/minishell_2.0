/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freecharmatrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:19:18 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/28 17:25:05 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charmatrixlen(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	ft_freecharmatrix(char **matrix)
{
	int	i;

	i = ft_charmatrixlen(matrix) - 1;
	while (i >= 0)
		free(matrix[i--]);
}
