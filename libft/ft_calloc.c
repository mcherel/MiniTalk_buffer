/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <mcherel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:05:41 by mcherel-          #+#    #+#             */
/*   Updated: 2022/06/13 10:40:32 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*allocates memory for n elements elementCount
 * size elementSize each and returns a pointer to the allocated memory. 
 * The memory is set to zero.*/

void	*ft_calloc( size_t elementCount, size_t elementSize )
{
	void	*tab;
	size_t	result;

	if (elementCount == 0 || elementSize == 0)
		return (NULL);
	result = elementSize * elementCount;
	if (elementCount != (result / elementSize))
		return (NULL);
	tab = malloc(result);
	if (!tab)
		return (free(tab), NULL);
	else
		ft_bzero(tab, result);
	return (tab);
}
