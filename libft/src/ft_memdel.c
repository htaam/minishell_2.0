#include "libft.h"

int	ft_memdel(void **ptr)
{
	if (*ptr)
	{
		ft_memset(*ptr, 0, ft_strlen(*ptr));
		free(*ptr);
		*ptr = 0;
		return (1);
	}
	return (0);
}
