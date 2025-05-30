/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnussler <mnussler@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:50:41 by mnussler          #+#    #+#             */
/*   Updated: 2025/05/30 02:32:58 by mnussler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *str, char sep)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == sep)
			++str;
		if (*str)
			count++;
		while (*str && *str != sep)
			++str;
	}
	return (count);
}

static int	get_word_len(char const *str, char sep)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != sep)
		len++;
	return (len);
}

/**
 * Allocates memory for a word in the split array
 * Frees all of the previously allocated memory if a word fails to allocate
 * Returns word on success, NULL on failure
 */
static char	*allocate_word(char const *str, int const word_len,
		char **result_on_failure)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
	{
		i = 0;
		while (result_on_failure[i])
		{
			free(result_on_failure[i]);
			++i;
		}
		free(result_on_failure);
		return (NULL);
	}
	ft_memcpy(word, str, word_len);
	word[word_len] = '\0';
	return (word);
}

/**
 * Init all result array elements to NULL, so that cleanup will be easier later
 */
static void	init_result_array(char **result, int const size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		result[i] = NULL;
		++i;
	}
}

/*
 * Splits a string into an array of strings using a delimiter
 * Returns the array on success, NULL on failure
 */
char	**ft_split(const char *s, char c)
{
	int		i;
	char	**result;
	int		word_count;
	int		len;

	word_count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	init_result_array(result, word_count + 1);
	i = 0;
	while (i < word_count)
	{
		while (*s && *s == c)
			++s;
		len = get_word_len(s, c);
		result[i] = allocate_word(s, len, result);
		if (!result[i])
			return (NULL);
		s += len;
		++i;
	}
	return (result);
}
