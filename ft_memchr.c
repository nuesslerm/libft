/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnussler <mnussler@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:37:21 by mnussler          #+#    #+#             */
/*   Updated: 2025/05/30 02:33:05 by mnussler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char const	*ptr;
	unsigned char		c_char;
	size_t				i;

	ptr = (unsigned char const *)s;
	c_char = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == c_char)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
