/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:46:45 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/19 14:10:10 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	char			s[10];
	int				i;

	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
	{
		nb = (unsigned int) n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		nb = (unsigned int) n;
	i = 0;
	while (nb > 0)
	{
		s[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar_fd(s[i], fd);
}
