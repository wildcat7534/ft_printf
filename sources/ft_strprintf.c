/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_strprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:08:03 by cmassol           #+#    #+#             */
/*   Updated: 2024/07/09 14:08:03 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_strprintf(va_list args, int len, int *totalchar)
{
    char	*str;
    int		i;

    str = va_arg(args, char *);
    i = 0;
    (*totalchar) += len;
    while (len--)
        ft_putchar_fd(str[i++], 1);
}