/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnussler <mnussler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:07:13 by mnussler          #+#    #+#             */
/*   Updated: 2025/05/13 02:07:17 by mnussler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static int	will_overflow(int result, int digit, int sign)
{
	if (sign == 1)
	{
		if (result > (INT_MAX - digit) / 10)
			return (1);
	}
	else
	{
		if (-result < (INT_MIN + digit) / 10)
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;
	int	digit;

	i = 0;
	sign = 1;
	result = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		digit = str[i] - '0';
		if (will_overflow(result, digit, sign))
			break ;
		result = 10 * result + digit;
		i++;
	}
	return (result * sign);
}
