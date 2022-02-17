#include "minishell.h"

int	count_pipes(char	**a)
{
	int	i;
	int	n;
	int	last_was_pipe;

	last_was_pipe = 0;
	i = 0;
	n = 0;
	while (a[i])
	{
		if (a[i][0] == '|' && last_was_pipe == 0)
		{
			last_was_pipe = 1;
			n++;
		}
		else if (a[i][0] == '|' && last_was_pipe == 1)
			return (-1);
		else
			last_was_pipe = 0;
		i++;
	}
	return (n);
}

char	**ft_extend_matrix(char **in, char *newstr)
{
	char	**out;
	int		len;
	int		i;

	i = -1;
	out = NULL;
	if (!newstr)
		return (in);
	len = ft_charmatrixlen(in);
	out = malloc(sizeof(char *) * (len + 2));
	out[len + 1] = NULL;
	if (!out)
		return (in);
	while (++i < len)
	{
		out[i] = ft_strdup(in[i]);
		if (!out[i])
		{
			ft_free_matrix(&in);
			ft_free_matrix(&out);
		}
	}
	out[i] = ft_strdup(newstr);
	ft_free_matrix(&in);
	return (out);
}

t_node	*make_node(char **a)
{
	int			i;
	t_node		*node;

	i = 0;
	node = malloc (sizeof(t_node));
	(*node).arg = NULL;
	(*node).cmd = ft_strdup(a[i]);
	(*node).in_file = 0;
	(*node).out_file = 1;
	while (a[i])
	{
		if (ft_strlen(a[i]) == 1 && a[i][0] == '|')
			break ;
		(*node).arg = ft_extend_matrix((*node).arg, a[i]);
		i++;
	}
	return (node);
}

t_node	**parse(char	**a)
{
	t_node		**node;
	int			num_pipes;
	int			i;
	int			j;

	i = 0;
	j = 0;
	num_pipes = count_pipes(a);
	node = malloc(sizeof(t_node) * (num_pipes + 1));
	while (a[i])
	{
		if (i == 0 && a[i][0] != '|')
		{
			node[0] = make_node(&a[i]);
			j++;
		}
		if (ft_strlen(a[i]) == 1
			&& a[i][0] == '|' && i != 0 && a[i + 1] != NULL)
		{
			node[j] = make_node(&a[i + 1]);
			j++;
		}
		i++;
	}
	return (node);
}
