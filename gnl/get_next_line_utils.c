#include "get_next_line.h"

int	ft_get_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_join_string(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newstr = malloc(ft_get_len(s1) + ft_get_len(s2) + 1);
	if (!newstr)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	if (s1)
		free(s1);
	return (newstr);
}

int	ft_get_eol(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (++i);
		i++;
	}
	return (0);
}

char	*ft_get_line(char **str, int nl_pos)
{
	char	*line;
	int		i;

	if (nl_pos == 0)
		nl_pos = ft_get_len(*str);
	line = malloc(nl_pos + 1);
	line[nl_pos] = '\0';
	i = 0;
	while (i < nl_pos)
	{
		line[i] = str[0][i];
		i++;
	}
	return (line);
}

char	*ft_next_line(char **str)
{
	char	*next;
	int		i;
	int		j;

	next = NULL;
	i = ft_get_len(*str) - ft_get_eol(*str);
	if (i != ft_get_len(*str) && i > 0)
	{
		next = malloc(i + 1);
		next[i++] = '\0';
		j = ft_get_len(*str);
		while (i-- > 0)
		{
			next[i] = str[0][j];
			j--;
		}		
	}
	free(*str);
	*str = next;
	return (next);
}