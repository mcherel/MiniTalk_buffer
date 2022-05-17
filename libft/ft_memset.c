/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:35:09 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/19 13:08:32 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* memset - fill memory with a constant byte */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		*((char *)pointer + i) = value;
		i++;
	}
	return (pointer);
}
