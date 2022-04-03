#include "minishell.h"

void	convertminmai(char *str, int conv)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (conv == 1)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}
