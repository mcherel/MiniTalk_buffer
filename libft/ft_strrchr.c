/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:46:16 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/26 09:29:12 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* return a pointer to the byte or 
 a null pointer if searchedChar does not occur in the string */
#include "libft.h"

char	*ft_strrchr( const char *string, int searchedChar )
{
	int	i;

	i = ft_strlen(string);
	while (i >= 0)
	{
		if (string[i] == (char)searchedChar)
			return ((char *)&string[i]);
		i--;
	}
	return (NULL);
}
