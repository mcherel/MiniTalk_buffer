# ifndef minitalk_h
 # define minitalk_h

 # include "libft.h"
 # include <signal.h>

//ERRORS
 # define ARG_INVALID   "ERROR: Invalid arguments: [./client] [server PID] [Your message]\n"
 # define PID_INVALID   "ERROR: Invalid server PID\n"
 # define NBA_INVALID   "ERROR: Invalid number of argumets. Allowed : "
 # define STR_EMPTY     "ERROR: Empty string!!! \n"
 # define SIG_ERROR     "ERROR: Signal problem!!! \n"

//MESSAGES
 # define MSG_WELCOME "Welcome, PID: "
 # define MSG_DELIVRD "Your message was delivered !!!!\n"

//CONSTANTES
# define SLEEP_TIME	200000

# endif