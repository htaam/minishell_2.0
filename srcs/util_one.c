/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:38:40 by tmatias           #+#    #+#             */
/*   Updated: 2022/04/10 16:42:54 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	whileexport(char **argu)
{
	int	i;

	i = 1;
	while (argu[i])
	{
		if (checkpos(argu[i], '=') != ft_strlen(argu[i]))
			tryexport(argu[i]);
		i++;
	}
}
