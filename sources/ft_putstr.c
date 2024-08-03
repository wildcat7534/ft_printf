/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:32:02 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/03 18:40:04 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putstr(char *s, int *totalchar)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		s = "(null)";
		while (s[i])
			ft_putcharlen(s[i++], totalchar);
		return ;
	}
	while (s[i])
		ft_putcharlen(s[i++], totalchar);
}
