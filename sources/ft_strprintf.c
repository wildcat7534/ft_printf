/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:08:03 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/01 11:30:15 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

void	ft_strprintf(char *str, int *totalchar)
{
    int i;
    int len;

    if (str == NULL)
    {   
        ft_putstr_fd("(null)", 1);
        return ;
    }
    len = ft_strlen(str);
    i = 0;
    (*totalchar) += len;
    while (len--)
        ft_putchar_fd(str[i++], 1);
}