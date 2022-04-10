/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:38:22 by tmatias           #+#    #+#             */
/*   Updated: 2022/04/10 16:38:23 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_quotes(char	**a)
{
	int		i;
	char	*temp;

	i = 0;
	while (a[i])
	{
		if ((a[i][0]) == '\'')
		{
			temp = ft_substr(a[i], 1, ft_strlen(a[i]) - 2);
			free(a[i]);
			a[i] = temp;
		}
		if ((a[i][0]) == '\"')
		{
			temp = ft_substr(a[i], 1, ft_strlen(a[i]) - 2);
			free(a[i]);
			a[i] = temp;
		}
		i++;
	}
}
