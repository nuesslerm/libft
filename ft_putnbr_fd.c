/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnussler <mnussler@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:51:29 by mnussler          #+#    #+#             */
/*   Updated: 2025/05/30 02:33:00 by mnussler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr_long;

	if (fd < 0)
		return ;
	nbr_long = n;
	if (nbr_long < 0)
	{
		ft_putchar_fd('-', fd);
		nbr_long = -nbr_long;
	}
	if (nbr_long >= 10)
	{
		ft_putnbr_fd(nbr_long / 10, fd);
	}
	ft_putchar_fd((nbr_long % 10) + '0', fd);
}
