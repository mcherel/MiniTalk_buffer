/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:23:47 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/19 14:18:33 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*returns the initial length of dst plus the length of src*/
/*guarantee to NUL-terminate the result (as long as size is larger than 0 */
/*as long as there is at least one byte free in dst)*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstl;
	size_t	srcl;
	size_t	i;

	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	if (dstl >= dstsize)
		return (dstsize + srcl);
	i = 0;
	while (src[i] != '\0' && (dstl + i + 1) < dstsize)
	{
		dst[dstl + i] = src[i];
		i++;
	}
	dst[dstl + i] = '\0';
	return (srcl + dstl);
}
