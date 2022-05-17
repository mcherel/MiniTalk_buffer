/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:01:27 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/19 14:19:16 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	newstr = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
