/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <mcherel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:15:53 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/27 13:26:14 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && i < (n - 1)
		&& str1[i] != '\0' && str2[i] != '\0')
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
/*The strcmp() function compares the two strings s1 and s2.*/
/* It returns an integer less than, equal to, or greater than zero*/
/* if s1 is found, respectively, to be less than, to match,*/
/* or be greater than s2.*/