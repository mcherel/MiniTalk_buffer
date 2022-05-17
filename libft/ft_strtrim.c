/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:33:20 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/19 13:43:30 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strt;
	int		len;

	if (!s1)
		return (NULL);
	while (*s1 && (ft_strchr(set, *s1)))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strrchr(set, s1[len]))
		len--;
	strt = ft_substr(s1, 0, len + 1);
	return (strt);
}
