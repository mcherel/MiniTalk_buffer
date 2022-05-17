/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:05:46 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/19 13:32:58 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*copies up to size - 1 characters from the NUL-terminated string src to dst, 
 * NUL-terminating the result.*/
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcl;

	srcl = ft_strlen(src);
	if (dstsize == 0)
		return (srcl);
	while (*src && --dstsize)
	{
		*dst++ = *src++;
	}
	*dst++ = '\0';
	return (srcl);
}
