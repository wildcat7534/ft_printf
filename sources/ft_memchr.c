/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:01:46 by cmassol           #+#    #+#             */
/*   Updated: 2024/06/06 19:50:29 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*str_cpy;
	unsigned char	c_cpy;

	str_cpy = (unsigned char *)str;
	c_cpy = (unsigned char)c;
	while (n--)
	{
		if (*str_cpy == c_cpy)
			return (str_cpy);
		str_cpy++;
	}
	return (NULL);
}
