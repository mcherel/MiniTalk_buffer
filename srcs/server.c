/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <mcherel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:14:25 by mcherel-          #+#    #+#             */
/*   Updated: 2022/06/13 16:10:21 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoinb(char *s1)
{
	char	*ret;
	int		i;

	if (!s1)
		return (NULL);
	i = -1;
	ret = ft_calloc(ft_strlen(s1) + 257, 1);
	if (!ret)
	{
		free(s1);
		exit(0);
	}
	while (s1[++i])
		ret[i] = (char)s1[i];
	free(s1);
	return (ret);
}

void	clear(char *str, int *i, int pid, int *j)
{
	ft_putstr_fd(str, 1);
	send_signal(pid, SIGUSR2);
	*i = 0;
	*j = 0;
	free(str);
}

char	*setup(int *j)
{
	char	*buff;

	*j = 1;
	buff = ft_calloc(257, 1);
	if (!buff)
		exit(0);
	return (buff);
}

void	handle_signal(int sig, siginfo_t *pid, void *del)
{
	static char	*buff;
	static int	i = 0;
	static int	j = 0;
	static int	count = 0;

	del += 0;
	if (!j)
		buff = setup(&j);
	buff[i] <<= 1;
	if (sig == SIGUSR1)
		buff[i] += 1;
	if (++count == 8)
	{
		count = 0;
		if (!buff[i])
		{
			clear(&buff[0], &i, pid->si_pid, &j);
			return ;
		}
		if (i != 0 && i % 255 == 0)
			buff = ft_strjoinb(buff);
		i++;
	}
	send_signal(pid->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd((int)getpid(), 1);
	ft_putstr_fd("\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
}
