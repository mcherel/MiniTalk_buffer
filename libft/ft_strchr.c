/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:01:23 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/19 13:25:42 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr( const char *string, int searchedChar )
{
	while (*string != '\0' && *string != (char)searchedChar)
		string++;
	if (*string == (char)searchedChar)
		return ((char *)string);
	return (NULL);
}
