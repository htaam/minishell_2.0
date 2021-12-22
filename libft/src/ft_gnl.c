/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:06:08 by tmatias           #+#    #+#             */
/*   Updated: 2021/05/05 16:06:42 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_calloc_set(size_t count, size_t size)
{
	void	*returning;
	int		len;
	void	*ptr;

	returning = malloc(count * size);
	if (returning == 0)
		return (NULL);
	len = size * count;
	ptr = returning;
	while (len--)
	{
		*(char *)returning = 0;
		returning = (char *)returning + 1;
	}
	return (ptr);
}

static void	gnl_aux1(int r, char **sav, char **temp, char *buff)
{
	char	*buff2;

	buff2 = buff;
	buff2[r] = 0;
	*temp = ft_strjoin(*sav, buff2);
	ft_memdel((void **)sav);
	*sav = *temp;
}

static int	gnl_aux2(int *r, char **sav, char **temp, char ***line)
{
	if (*r == 0)
		**line = ft_strdup(*sav);
	else if (r > 0)
		**line = ft_substr(*sav, 0, (ft_strchr(*sav, '\n') - *sav));
	if (r > 0)
		*temp = ft_strdup(*sav + (ft_strlen(**line) + 1));
	else
		*temp = ft_strdup(*sav + (ft_strlen(**line)));
	ft_memdel((void **)sav);
	*sav = *temp;
	return (*r);
}

int	ft_gnl(int fd, char **line)
{
	int			r;
	static char	*sav[10240];
	char		buff[BUFFER_SIZE + (1)];
	char		*temp;

	r = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if (sav[fd] == NULL)
		sav[fd] = ft_calloc_set(1, sizeof(char));
	while (!(ft_strchr(sav[fd], '\n')))
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r > 0)
			gnl_aux1(r, &sav[fd], &temp, buff);
		else
			break ;
	}
	if (r < 0)
		return (-1);
	if (gnl_aux2(&r, &sav[fd], &temp, &line) == 0)
		return (0 * ft_memdel((void **)&sav[fd]));
	return (1);
}
