/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <mcherel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:31:22 by mcherel-          #+#    #+#             */
/*   Updated: 2022/06/13 16:34:52 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>

//ERRORS
# define ARG_INVALID   "ERROR: Invalid arguments: \
                        [./client] [server PID] [Your message]\n"
# define PID_INVALID   "ERROR: Invalid server PID\n"
# define NBA_INVALID   "ERROR: Invalid number of argumets. Allowed : "
# define STR_EMPTY     "ERROR: Empty string!!! \n"
//# define SIG_ERROR     "ERROR: Signal problem!!! \n"

//MESSAGES
# define MSG_WELCOME "Welcome, PID: "
# define MSG_DELIVRD "Your message was delivered !!!!\n"

//CONSTANTES
# define SLEEP_TIME	20000

void	send_signal(int pid, int signum);

#endif