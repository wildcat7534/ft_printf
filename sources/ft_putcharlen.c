/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:54:50 by cmassol           #+#    #+#             */
/*   Updated: 2024/06/11 17:27:12 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_putcharlen_fd(char c, int fd, int *totalchar)
{
	write(fd, &c, 1);
	(*totalchar)++;
}