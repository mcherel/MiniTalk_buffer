/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:33:05 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/26 15:20:54 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*strc;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	strc = (char *)malloc((len + 1) * sizeof(char));
	if (!strc)
		return (0);
	i = 0;
	while (i < len)
	{
		strc[i] = s1[i];
		i++;
	}
	strc[i] = '\0';
	return (strc);
}
/* allocates sufficient memory for a copy of the string s1, does the copy, 
 * and returns a pointer to it
 * The pointer may subsequently be used as an argument to the function free*/
