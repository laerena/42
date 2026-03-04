#include <stdlib.h>

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
			count++;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t'
			&& str[i] != '\n')
			i++;
	}
	return (count);
}

void	copy(char *tab, char *str, int start, int end)
{
	int	j = 0;

	while (start < end)
		tab[j++] = str[start++];
	tab[j] = '\0';
}

int	find_next(char *str, int *start, int *end)
{
	int	i;

	i = *end;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n'))
		i++;
	*start = i;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	*end = i;
	return (*start < *end);
}

int	fill(char **tab, char *str)
{
	int	i;
	int	word;
	int	start;
	int	end;

	i = 0;
	word = 0;
	start = 0;
	end = 0;
	while (find_next(str, &start, &end))
	{
		tab[word] = malloc (sizeof(char) * (end - start + 1));
		if (tab[word] == NULL)
		{
			i = 0;
			while (i < word)
				free(tab[i++]);
			free(tab);
			return (0);
		}
		copy(tab[word], str, start, end);
		word++;
	}
	tab[word] = NULL;
	return (1);
}

char	**ft_split(char *str)
{
	int		size;
	char	**out;

	size = count_words(str);
	out = malloc((sizeof(char *) * (size + 1)));
	if (!out)
		return (NULL);
	if (!fill(out, str))
	{
		free(out);
		return (NULL);
	}
	return (out);
}