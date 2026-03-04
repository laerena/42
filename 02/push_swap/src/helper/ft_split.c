#include <stdlib.h>

static int	is_sep(char ch, char c)
{
	return (ch == c);
}

/*
** skip separators, count a word, skip it, repeat until end of string
*/
static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && is_sep(*s, c))
			s++;
		if (*s)
		{
			count++;
			while (*s && !is_sep(*s, c))
				s++;
		}
	}
	return (count);
}

/*
** allocate and copy a word from the string (until separator or end)
** function does not skip separators, it assumes s is alreadt at a word start
*/
static char	*dup_word(char const *s, char c)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (s[len] && !is_sep(s[len], c))
		len++;
	word = (char *)malloc((size_t)len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **arr, int filled)
{
	int	i;

	i = 0;
	while (i < filled)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/*
** main split function: allocate array, fill with duplicated words, handle errors
*/
char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		wc;
	int		i;

	if (!s)
		return (NULL);
	wc = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < wc)
	{
		while (*s && is_sep(*s, c))
			s++;
		arr[i] = dup_word(s, c);
		if (!arr[i])
			return (free_all(arr, i), NULL);
		while (*s && !is_sep(*s, c))
			s++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
