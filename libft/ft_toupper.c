/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:55:38 by mcherel-          #+#    #+#             */
/*   Updated: 2021/12/19 13:46:00 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_toupper( int c )
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
