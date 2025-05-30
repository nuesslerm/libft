/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnussler <mnussler@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 03:24:58 by mnussler          #+#    #+#             */
/*   Updated: 2025/05/30 02:32:49 by mnussler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c_char;
	char	*last_occurrence;

	c_char = (char)c;
	last_occurrence = NULL;
	while (*s)
	{
		if (*s == c_char)
			last_occurrence = (char *)s;
		s++;
	}
	if (c_char == '\0')
		return ((char *)s);
	return (last_occurrence);
}
