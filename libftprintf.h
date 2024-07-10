/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:38:18 by cmassol           #+#    #+#             */
/*   Updated: 2024/06/11 17:53:28 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "headers/libft.h"
# include <stdarg.h>



//int		count_args(const char *format);
//char	ft_strfindchr(const char *str, int c);
//int		ft_printargs(char argfind, va_list args);
//int		ft_printf(const char *format, ...);
int		ft_nbrlen(int n);
void	ft_putnbrlen_fd(int n, int fd, int *totalchar);
void	ft_putcharlen_fd(char c, int fd, int *totalchar);
int		ft_atoi_base(char *str, char *base);
void	ft_putnbrbase_fd(int n, char *base, int *totalchar);
void	ft_strprintf(va_list args, int len, int *totalchar);

#endif