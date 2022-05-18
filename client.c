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
		ft_putstr_fd("\n\n", 1);
		ft_putstr_fd(MSG_DELIVRD, 1);
		exit(0);
	}
}

void	send_signal(int pid, int signum)
{
	if (kill(pid, signum) == -1)
		exit(EXIT_FAILURE);
}

void	send_byte(int pid, char c)
{
	unsigned char	mask;

	mask = 1 << 7;
	while (mask)
	{
		if (g_check)
		{
			g_check = 0;
			if (c & mask)
				send_signal(pid, SIGUSR1);
			else
				send_signal(pid, SIGUSR2);
			mask >>= 1;
			while (!g_check)
				;
		}
	}
}

int send_str(int pid, char *str)
{
	int	i;

	if(ft_strlen(str) != 0)
	{
	while (str)
		send_byte(pid, *str++);
	i = -1;
	while (++i != 8)
		send_byte(pid, 0);
	return (1);
	}
	ft_putstr_fd(STR_EMPTY, 2);
	return (0);
}

int check_argc(int argc)
{
	if (argc == 3)
		return (1);
	ft_putstr_fd(NBA_INVALID, 2);
	ft_putnbr_fd(3, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(ARG_INVALID, 2);	
	return (0);
}

int check_pid(int pid)
{
	if ((pid <= 0) || (kill(pid, 0)))
	{
		ft_putstr_fd(PID_INVALID, 2);
		ft_putstr_fd(ARG_INVALID, 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int pid;

	signal(SIGUSR1, &handle);
	signal(SIGUSR2, &handle);
	if(!check_argc(argc))
		return (1);
	pid = ft_atoi(argv[1]);
	if(!check_pid(pid))
		return (1);
	if(!send_str(pid, &argv[2][0]))
		return (1);
	while (1)
		continue ;
}
