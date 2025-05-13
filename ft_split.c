#include "libft.h"
#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static void	free_split_array(char **arr, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char		**result_array;
	size_t		num_words;
	size_t		i;
	const char	*temp_s;
	const char	*word_start;
	size_t		word_len;

	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	result_array = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!result_array)
		return (NULL);
	temp_s = s;
	i = 0;
	while (i < num_words)
	{
		while (*temp_s && *temp_s == c)
			temp_s++;
		word_start = temp_s;
		word_len = 0;
		while (temp_s[word_len] && temp_s[word_len] != c)
			word_len++;
		result_array[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!result_array[i])
		{
			free_split_array(result_array, i);
			return (NULL);
		}
		ft_memcpy(result_array[i], word_start, word_len);
		result_array[i][word_len] = '\0';
		temp_s += word_len;
		i++;
	}
	result_array[num_words] = NULL;
	return (result_array);
}
