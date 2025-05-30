/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnussler <mnussler@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:59:03 by mnussler          #+#    #+#             */
/*   Updated: 2025/05/30 02:32:50 by mnussler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_idx;
	size_t	n_idx;
	size_t	needle_len;

	if (!needle || *needle == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	h_idx = 0;
	while (haystack[h_idx] && h_idx + needle_len <= len)
	{
		n_idx = 0;
		while (needle[n_idx] && needle[n_idx] == haystack[h_idx + n_idx])
			n_idx++;
		if (needle[n_idx] == '\0')
			return ((char *)(haystack + h_idx));
		h_idx++;
	}
	return (NULL);
}
