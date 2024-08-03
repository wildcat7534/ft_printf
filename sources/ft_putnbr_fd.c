/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:26:30 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/03 18:42:43 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = nbr * -1;
		ft_putnbr_fd(nbr, fd);
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd(nbr % 10 + '0', fd);
	}
	else if (nbr < 10)
		ft_putchar_fd(nbr + '0', fd);
}
