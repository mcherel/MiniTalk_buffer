/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:37:57 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/19 13:01:37 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* copies size bytes from memory area src to memory area dest. 
 * The memory areas should not overlap. 
 * Use memmove(3) if the memory areas do overlap.*/
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (size > i)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}
