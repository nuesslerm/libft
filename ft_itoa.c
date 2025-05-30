/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnussler <mnussler@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:32:21 by mnussler          #+#    #+#             */
/*   Updated: 2025/05/30 02:33:13 by mnussler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_fill_chars_from_nbr(char *str, unsigned int nbr, int len)
{
	while (nbr > 0)
	{
		str[len--] = '0' + (nbr % 10);
		nbr = nbr / 10;
	}
	return (str);
}

static int	ft_get_length(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	nbr;

	len = ft_get_length(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	str[0] = '0';
	if (n < 0)
	{
		nbr = -n;
		str[0] = '-';
	}
	else
		nbr = n;
	str = ft_fill_chars_from_nbr(str, nbr, len);
	return (str);
}
