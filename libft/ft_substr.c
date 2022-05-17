/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:32:48 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/26 09:14:50 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Alloue (avec malloc(3)) et retourne une chaine de
  caractères issue de la chaine ’s’.
  Cette nouvelle chaine commence à l’index ’start’ et
  a pour taille maximale ’len’*/
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		cpy = (char *)malloc(sizeof(char));
		if (!cpy)
			return (NULL);
		ft_strlcpy(cpy, "", 1);
		return (cpy);
	}
	if (len > ft_strlen(&s[start]))
		cpy = (char *)malloc(sizeof(char) * ft_strlen(&s[start]) + 1);
	else
		cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, &s[start], len + 1);
	return (cpy);
}
