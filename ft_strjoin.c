#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	s2_len = 0;
	if (s2)
		s2_len = ft_strlen(s2);
	joined_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!joined_str)
		return (NULL);
	if (s1)
		ft_memcpy(joined_str, s1, s1_len);
	else
		*joined_str = '\0';
	if (s2)
		ft_memcpy(joined_str + s1_len, s2, s2_len);
	joined_str[s1_len + s2_len] = '\0';
	return (joined_str);
}
