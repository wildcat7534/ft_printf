/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:45:59 by cmassol           #+#    #+#             */
/*   Updated: 2024/06/11 17:27:12 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_putnbrlen_fd(int n, int fd, int *totalchar)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	else if (nbr >= 10)
	{
		ft_putnbrlen_fd(nbr / 10, fd, totalchar);
		ft_putnbrlen_fd((char)nbr % 10, fd, totalchar);
	}
	else if (nbr < 10)
	{
		c = (char)(nbr + '0');
		write(fd, &c, fd);
		(*totalchar)++;
	}
}
