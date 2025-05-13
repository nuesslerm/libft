#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	long	lnb;
	int		length;
	char	*res;
	int		sign;

	lnb = n;
	sign = 1;
	if (lnb < 0)
	{
		sign = -1;
		lnb = -lnb;
	}
	length = 0;
	if (lnb == 0)
		length = 1;
	else
	{
		long temp = lnb;
		while (temp > 0)
		{
			temp /= 10;
			length++;
		}
	}
	if (sign == -1)
		length++;
	res = (char *)malloc(sizeof(char) * (length + 1));
	if (!res)
		return (NULL);
	res[length] = '\0';
	length--;
	if (lnb == 0)
		res[0] = '0';
	else
	{
		while (lnb > 0)
		{
			res[length--] = (lnb % 10) + '0';
			lnb /= 10;
		}
	}
	if (sign == -1 && n != 0)
		res[0] = '-';
	return (res);
}
