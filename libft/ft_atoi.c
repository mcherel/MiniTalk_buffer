/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <mcherel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:40:51 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/27 13:27:23 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La fonction atoi() convertit le début de la chaîne 
  pointée par nptr en entier de type int */
#include "libft.h"

static int	ft_isspace(char c);

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspace(nptr[i]) && (nptr[i] != '\0'))
		i++;
	if (!ft_isprint(nptr[i]))
		return (0);
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while ((nptr[i] != '\0') && ft_isdigit(nptr[i]))
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		if ((nbr * sign) < (int)INT_MINI)
			return (0);
		if (nbr > INT_MAXI && (nbr * sign) != (int)INT_MINI)
			return (-1);
		i++;
	}
	return (sign * nbr);
}

static int	ft_isspace(char c)
{
	if ((c == ' ')
		|| (c == '\t')
		|| (c == '\n')
		|| (c == '\f')
		|| (c == '\v')
		|| (c == '\r'))
		return (1);
	return (0);
}
