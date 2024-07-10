/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase16.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:19:12 by cmassol           #+#    #+#             */
/*   Updated: 2024/07/09 14:19:12 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_putnbrbase_fd(int n, char *base, int *totalchar)
{
    int		base_len;

    base_len = ft_strlen(base);
    if (n == -2147483648)
    {
        if (base[10] == 'a')
            ft_putstr_fd("fff ffff 8000 0000", 1);
        else
            ft_putstr_fd("FFFF FFFF 8000 0000", 1);
        return ;
    }
    if (n < 0)
    {
        ft_putcharlen_fd('-', 1, totalchar);
        n *= -1;
    }
    if (n >= base_len)
    {
        ft_putnbrbase_fd(n / base_len, base, totalchar);
        ft_putcharlen_fd(base[n % base_len], 1, totalchar);
    }
    else
        ft_putcharlen_fd(base[n], 1, totalchar);
}