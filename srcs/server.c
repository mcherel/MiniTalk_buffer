/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <mcherel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:14:25 by mcherel-          #+#    #+#             */
/*   Updated: 2022/06/14 15:30:25 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoinb(char *str)
{
	char	*tmp;
	int		i;

	if (!str)
		return (NULL);
	i = -1;
	tmp = ft_calloc(ft_strlen(str) + 257, 1);
	if (!tmp)
	{
		free(str);
		exit(0);
	}
	while (str[++i])
		tmp[i] = (char)str[i];
	free(str);
	return (tmp);
}

void	print_and_free(char *str, int *i, int pid, int *j)
{
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
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
			print_and_free(&buff[0], &i, pid->si_pid, &j);
			return ;
		}
		if (i != 0 && i % 255 == 0)
			buff = ft_strjoinb(buff);
		i++;
	}
	send_signal(pid->si_pid, SIGUSR1);
}

/* sa_flags spécifie un ensemble d'attributs  */
/* 	qui modifient le comportement du signal */
/* SA_SIGINFO (Depuis Linux 2.2)*/
/*- Le gestionnaire de signal recevra trois arguments, 
et non plus un seul.*/
/*- Dans ce cas, il faut utiliser le membre sa_sigaction 
et non pas sa_handler.*/
/* - Cette fonction prend le numéro du signal comme premier argument, */
/*    un pointeur sur un siginfo_t comme second argument */
/*    et un pointeur sur un ucontext_t (transtypé en void *) 
comme troisième argument. */
/* struct sigaction {
    void     (*sa_handler) (int);
    void     (*sa_sigaction) (int, siginfo_t *, void *);
    sigset_t   sa_mask;
    int        sa_flags;
    void     (*sa_restorer) (void);
};
   */
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
