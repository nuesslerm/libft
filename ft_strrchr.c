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
