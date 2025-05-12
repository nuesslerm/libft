#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
			c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (is_whitespace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		if (sign == 1 && (result > (long)((unsigned long)~0 >> 1) / 10 || \
			(result == (long)((unsigned long)~0 >> 1) / 10 && (*str - '0') > (int)((unsigned long)~0 >> 1) % 10)))
			return (-1);
		else if (sign == -1 && (result > (long)((unsigned long)~0 >> 1) / 10 || \
			(result == (long)((unsigned long)~0 >> 1) / 10 && (*str - '0') > (int)(((unsigned long)~0 >> 1) + 1) % 10)))
			return (0);
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(result * sign));
}
