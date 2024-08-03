/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:17:38 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/03 18:53:11 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdarg.h>

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
	uintptr_t	nb;

	if (argfind == '\0')
		return ;
	if ('c' == argfind)
		ft_putcharlen((char)va_arg(args, int), totalchar);
	if ('s' == argfind)
		ft_putstr(va_arg(args, char *), totalchar);
	if ('p' == argfind)
	{
		nb = (uintptr_t)va_arg(args, void *);
		if (nb == 0)
			ft_putstr("(nil)", totalchar);
		else
			return (ft_putstr("0x", totalchar), ft_putptr(nb, totalchar));
	}
	if ('x' == argfind || 'X' == argfind)
		ft_putnbrbase(va_arg(args, int), totalchar, argfind);
	if ('d' == argfind || 'i' == argfind)
		ft_putnbrlen(va_arg(args, int), totalchar);
	if ('u' == argfind)
		ft_putnbrlen((unsigned int)va_arg(args, int), totalchar);
	if ('%' == argfind)
		ft_putcharlen('%', totalchar);
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
			ft_putcharlen(*format, &totalchar);
		format++;
	}
	va_end(args);
	return (totalchar);
}
/*
#include <assert.h>
#include <stdio.h>
#include <limits.h>
	void ft_putptr(void *ptr) {
    printf("0x%lx\n", (unsigned long)ptr);
	ft_printf("0x%x",ptr);
	}
int	main(void)
{
	int	nbrprint = 0;
	int	nbrprint2 = 0;
	int	nbrprint3 = 0;
	int	nbrprint4 = 0;
	int	nbrprint5 = 0;
	int	nbrprint6 = 0;
	int	nbrprint7 = 0;
	int nbrprint8 = 0;
	
	char	charac = 'W';
	char	charac0 = '\0';
	int	nbr = 42;
	int nbr2 = 56;
	char *str = " world! ^^";
	int	*ptr = &nbr;
	int *ptr2 = &nbr2;
	int nbr3 = INT_MAX;
	int nbr4 = INT_MIN;
	int nbr5 = -2;
	int nbr6 = 2147483646;
	int *nbr7 = NULL;
	char *str2 = NULL;
	int	nbr8 = 0;
	//unsigned long nbr_unsigned_long = 4294967295;
	

	nbrprint = ft_printf("Hello 1 %c!\n avec %d, %s\n", charac, nbr, str);
 	nbrprint2 = ft_printf("Hello 2 %c!\n avec %d, %d, %s\n", charac, nbr, nbr2, str);
	nbrprint3 = ft_printf("Hello 3 %d, %s\n", nbr, str);
	nbrprint4 = ft_printf("Hello 4 %d, %d, %d, %d, %s\n", nbr, nbr, nbr, nbr, str);
	nbrprint5 = ft_printf("Hello 5 %d, %s, %c, %s, %s\n", nbr, str, charac0, str, str);
	nbrprint6 = ft_printf("Hello 6 %d, %s, %c, %s, %s\n", nbr, str, charac0, str, str);
	nbrprint7 = ft_printf("Hello 7 %d, %s, %c, %s, %s, %p, %X, %x, %x, %p\n", nbr, str, charac0, str, str, nbr7, nbr3, nbr5, nbr6, ptr);
	nbrprint8 = ft_printf("Hello 8 %p, %s, %d, %x, %p\n", nbr7, str2, nbr4, nbr8, ptr2);
	//assert(nbrprint == printf("Hello, %c!\n avec %d, %s\n", charac, nbr, str));
	// assert (nbrprint2 == printf("Hello, %c!\n avec %d, %d, %s", charac, nbr, nbr2, str);

	printf("comp %d: %d\n", nbrprint, printf("Hello 1 %c!\n avec %d, %s\n", charac, nbr, str));
	printf("comp 2 %d: %d\n", nbrprint2, printf("Hello 2 %c!\n avec %d, %d, %s\n", charac, nbr, nbr2, str));
	printf("comp 3 %d: %d\n", nbrprint3, printf("Hello 3 %d, %s\n", nbr, str));
	printf("comp 4 %d: %d\n", nbrprint4, printf("Hello 4 %d, %d, %d, %d, %s\n", nbr, nbr, nbr, nbr, str));
	printf("comp 5 %d: %d\n", nbrprint5, printf("Hello 5 %d, %s, %c, %s, %s\n", nbr, str, charac0, str, str));
	printf("comp 6 %d: %d\n", nbrprint6, printf("Hello 6 %d, %s, %c, %s, %s\n", nbr, str, charac0, str, str));
	printf("comp 7 %d: %d\n", nbrprint7, printf("Hello 7 %d, %s, %c, %s, %s, %p, %X, %x, %x, %p\n", nbr, str, charac0, str, str, nbr7, nbr3, nbr5, nbr6, ptr));
	printf("comp 8 %d: %d\n", nbrprint8, printf("Hello 8 %p, %s, %d, %x, %p\n", nbr7, str2, nbr4, nbr8, ptr2));


    void *ptrt = malloc(10);
    ft_putptr(ptrt);
    free(ptrt);
	
	return (0);
}*/
