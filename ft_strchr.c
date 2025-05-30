/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnussler <mnussler@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 03:19:06 by mnussler          #+#    #+#             */
/*   Updated: 2025/05/30 02:32:58 by mnussler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_char;

	c_char = (char)c;
	while (*s)
	{
		if (*s == c_char)
			return ((char *)s);
		s++;
	}
	if (c_char == '\0')
		return ((char *)s);
	return (NULL);
}
