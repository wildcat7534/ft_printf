/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:38:18 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/03 18:21:57 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putnbrlen(long n, int *totalchar);
void	ft_putcharlen(char c, int *totalchar);
void	ft_putnbrbase(unsigned int n, int *totalchar, char param);
void	ft_putstr(char *str, int *totalchar);
void	ft_putptr(uintptr_t ptr, int *totalchar);

#endif