/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:45:12 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/26 09:28:53 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && len > i && little[j] != '\0')
	{
		if (big[i] == little[j])
			j++;
		else if (j != 0)
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	if (j > 0 && little[j] == '\0')
		return ((char *)&big[i - j]);
	return (NULL);
}
/*locates the	first occurrence of the	null-terminated string little in the
 * string big, where not more than	len characters are searched.*/
