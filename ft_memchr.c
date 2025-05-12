#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		c_char;
	size_t				i;

	ptr = (const unsigned char *)s;
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
