#include "libc.h"

int	ft_char_count(char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			count++;
		}
		i++;
	}
	return (count);
}