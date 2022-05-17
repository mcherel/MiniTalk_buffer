/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <mcherel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:14:18 by mcherel-          #+#    #+#             */
/*   Updated: 2022/05/04 19:03:28 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_check = 1;

void	handle(int sig)
{
	if (sig == SIGUSR1)
		g_check = 1;
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("Message received.\n", 1);
		exit(0);
	}
}

void	chopper(int pid, char c)
{
	unsigned char	mask;

	mask = 1 << 7;
	while (mask)
	{
		if (g_check)
		{
			g_check = 0;
			if (c & mask)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			mask >>= 1;
			usleep(2);
		}
	}
}

int	main(int argc, char **argv)
{
	int					i;

	i = -1;
	signal(SIGUSR1, &handle);
	signal(SIGUSR2, &handle);
	if (argc != 3 || kill(ft_atoi(argv[1]), 0))
		return (1);
	while (argv[2][++i])
		chopper(ft_atoi(argv[1]), argv[2][i]);
	i = -1;
	while (++i != 8)
		chopper(ft_atoi(argv[1]), 0);
	while (1)
		continue ;
}
