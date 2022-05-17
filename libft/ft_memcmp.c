/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:00:48 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/19 12:58:58 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*function compares the first n bytes (each interpreted as unsigned char) 
 * of the memory areas s1 and s2*/
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n-- && n != 0 && *ss1 == *ss2)
	{
		ss1++;
		ss2++;
	}
	if (*ss1 != *ss2)
		return (*ss1 - *ss2);
	return (0);
}
