/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:44:48 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/19 12:56:12 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*locates the first occurrence of c converted to an unsigned char in string s*/
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n != 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
