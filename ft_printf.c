/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:17:38 by cmassol           #+#    #+#             */
/*   Updated: 2024/06/11 18:07:11 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

#include <stdio.h>

int	ft_printf(const char *format, ...);

char	ft_strfindchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return (str[i]);
		i++;
	}
	return ('\0');
}

void	ft_selectargs(char argfind, va_list args, int *totalchar)
{
	if ('c' == argfind)
		ft_putcharlen_fd((char)va_arg(args, int), 1, totalchar);
	if ('s' == argfind)
		ft_strprintf(args, ft_strlen((char *) va_arg(args, char *)), totalchar);
	if ('d' == argfind || 'i' == argfind)
		ft_putnbrlen_fd(va_arg(args, int), 1, totalchar);
	if ('p' == argfind)
	{
		//ft_putcharlen_fd('0', 1, totalchar);
		//ft_putcharlen_fd('x', 1, totalchar);
		// utiliser un simple putnbrbase16 
		//ft_putstr_fd(ft_convert_base(((char *)va_arg(args, void *)), "0123456789", "0123456789abcdef"), 1);
	}
	if ('x' == argfind)
		ft_putnbrbase_fd(va_arg(args, int), "0123456789abcdef", totalchar);
	if ('X' == argfind)
		ft_putnbrbase_fd(va_arg(args, int), "0123456789ABCDEF", totalchar);
	if ('%' == argfind)
		ft_putcharlen_fd('%', 1, totalchar);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		totalchar;
	char	argfind;

	totalchar = 0;
	va_start(args, format);
	while (format < (format + ft_strlen(format)))
	{
		if ((char) *format == '%')
		{
			format++;
			argfind = ft_strfindchr("cspdiuxX%", (char) *format);
			ft_selectargs(argfind, args, &totalchar);
		}
		else
			ft_putcharlen_fd(*format, 1, &totalchar);
		format++;
	}
	va_end(args);
	return (totalchar);
}
#include <assert.h>
#include <stdio.h>
#include <limits.h>
int	main()
{
	int	nbrprint = 0;
	int	nbrprint2 = 0;
	int	nbrprint3 = 0;
	int	nbrprint4 = 0;
	int	nbrprint5 = 0;
	int	nbrprint6 = 0;
	int	nbrprint7 = 0;

	char	charac = 'W';
	char	charac0 = '\0';
	int	nbr = 42;
	int nbr2 = 56;
	char *str = " world! ^^";
	int	*ptr = &nbr;
	int nbr3 = INT_MAX;
	int nbr4 = INT_MIN;
	

	nbrprint = ft_printf("Hello, %c!\n avec %d, %s\n", charac, nbr, str);
	nbrprint2 = ft_printf("Hello, %c!\n avec %d, %d, %s\n", charac, nbr, nbr2, str);
	nbrprint3 = ft_printf("Hello %d, %s\n", nbr, str);
	nbrprint4 = ft_printf("Hello %d, %d, %d, %d, %s\n", nbr, nbr, nbr, nbr, str);
	nbrprint5 = ft_printf("Hello %d, %s, %c, %s, %s\n", nbr, str, charac0, str, str);
	nbrprint6 = ft_printf("Hello %d, %s, %c , %s, %c\n", nbr, str, charac0, str, str);
	nbrprint7 = ft_printf("Hello %d, %s, %c, %s, %c, %d, %d\n", nbr, str, charac0, str, str, nbr3, nbr4);
	//assert(nbrprint == printf("Hello, %c!\n avec %d, %s\n", charac, nbr, str));
	// assert (nbrprint2 == printf("Hello, %c!\n avec %d, %d, %s", charac, nbr, nbr2, str);

	printf("\n ft_printf %d: %d\n", nbrprint, printf("Hello, %c!\n avec %d, %s\n", charac, nbr, str));
	printf("\n ft_printf2 %d: %d\n", nbrprint2, printf("Hello, %c!\n avec %d, %d, %s\n", charac, nbr, nbr2, str));
	printf("\n ft_printf3 %d: %d\n", nbrprint3, printf("Hello %d, %s\n", nbr, str));
	printf("\n ft_printf4 %d: %d\n", nbrprint4, printf("Hello %d, %d, %d, %d, %s\n", nbr, nbr, nbr, nbr, str));
	printf("\n ft_printf5 %d: %d\n", nbrprint5, printf("Hello %d, %s, %c, %s, %s\n", nbr, str, charac0, str, str));
	printf("\n ft_printf6 %d: %d\n", nbrprint6, printf("Hello %d, %s, %c, %s, %s\n", nbr, str, charac0, str, str));
	printf("\n ft_printf7 %d: %d\n", nbrprint7, printf("Hello %d, %s, %c, %s, %s, %d, %d\n", nbr, str, charac0, str, str, nbr3, nbr4));
	return (0);
}
