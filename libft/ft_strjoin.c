/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:26:03 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/19 14:12:41 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	unsigned int	l1;
	unsigned int	l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	new = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, l1 + 1);
	ft_strlcpy(&new[l1], s2, l2 + 1);
	return (new);
}
