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

	// measure word length
	len = 0;
	while (s[len] && !is_sep(s[len], c))
		len++;
	// allocate memory for word + null terminator len + 1
	word = (char *)malloc((size_t)len + 1);
	if (!word)
		return (NULL);
	// copy characters to new string
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
	// count how many words we will have to allocate
	wc = count_words(s, c);
	// alocate array of char* (w + 1), last one is NULL
	arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < wc)
	{
		// move s to the start of the next word (skip separators)
		while (*s && is_sep(*s, c))
			s++;
		// duplicate the word at s and store in array
		arr[i] = dup_word(s, c);
		if (!arr[i])
			return (free_all(arr, i), NULL);
		// move s to the end of the current word (skip non-separators)
		while (*s && !is_sep(*s, c))
			s++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
