#include "minishell.h"

// "<|>"
static int	count_words(char *str, char *set, int count)
{
	int		q[2];
	int		i;

	i = 0;
	q[0] = 0;
	q[1] = 0;
	while (str && str[i] != '\0')
	{
		count++;
		if (!ft_strchr(set, str[i]))
		{
			while ((!ft_strchr(set, str[i]) || q[0] || q[1]) && str[i] != '\0')
			{
				q[0] = (q[0] + (!q[1] && str[i] == '\'')) % 2;
				q[1] = (q[1] + (!q[0] && str[i] == '\"')) % 2;
				i++;
			}
			if (q[0] || q[1])
				return (-1);
		}
		else
			i++;
	}
	return (count);
}


static char	**fill_array(char **aux, char *str, char *set, int i[3])
{
	int		q[2];

	q[0] = 0;
	q[1] = 0;
	while (str && str[i[0]] != '\0')
	{
		i[1] = i[0];
		if (!ft_strchr(set, str[i[0]]))
		{
			while ((!ft_strchr(set, str[i[0]]) || q[0] || q[1]) && str[i[0]])
			{
				q[0] = (q[0] + (!q[1] && str[i[0]] == '\'')) % 2;
				q[1] = (q[1] + (!q[0] && str[i[0]] == '\"')) % 2;
				i[0]++;
			}
		}
		else
			i[0]++;
		aux[i[2]++] = ft_substr(str, i[1], i[0] - i[1]);
	}
	return (aux);
}

char	**split_set(char	*str, char *set)
{
	char	**aux;
	int		nwords;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (!str)
		return (NULL);
	nwords = count_words(str, set, 0);
	if (nwords == -1)
		return (NULL);
	aux = malloc((nwords + 1) * sizeof(char *));
	if (aux == NULL)
		return (NULL);
	aux = fill_array(aux, str, set, i);
	aux[nwords] = NULL;
	return (aux);
}

char	**matrix_replace_i(char ***big, char **small, int n)
{
	char	**aux;
	int		i[3];

	i[0] = -1;
	i[1] = -1;
	i[2] = -1;
	if (!big || !*big || n < 0 || n >= ft_charmatrixlen(*big))
		return (NULL);
	aux = ft_calloc(ft_charmatrixlen(*big)
			+ ft_charmatrixlen(small), sizeof(char *));
	while (aux && big[0][++i[0]])
	{
		if (i[0] != n)
			aux[++i[2]] = ft_strdup(big[0][i[0]]);
		else
		{
			while (small && small[++i[1]])
				aux[++i[2]] = ft_strdup(small[i[1]]);
		}
	}
	ft_free_matrix(big);
	*big = aux;
	return (*big);
}

char	**ft_subsplit(char	**a)
{
	char		**temp;
	int			i;

	i = 0;
	while (a[i])
	{
		temp = split_set(a[i], "<|>");
		matrix_replace_i(&a, temp, i);
		i += ft_charmatrixlen(temp);
		ft_free_matrix(&temp);
	}
	return (a);
}
