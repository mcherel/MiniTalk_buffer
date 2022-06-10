# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcherel- <mcherel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 18:22:08 by mcherel-          #+#    #+#              #
#    Updated: 2022/05/04 15:19:38 by mcherel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = clang

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS_CLIENT = client.c

SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

NAME_CLIENT = client

NAME_SERVER = server

LIBFT = ./libft/libft.a

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@ -Ilibft

$(NAME_CLIENT):	$(OBJS_CLIENT) $(LIBFT)
				$(CC) $< -o $@ -Llibft -lft 

$(NAME_SERVER):	$(OBJS_SERVER) $(LIBFT)
				$(CC) $< -o $@ -Llibft -lft 

$(LIBFT):
				make -C libft all

all:			$(NAME_CLIENT) $(NAME_SERVER)

clean:
				make clean -C ./libft
				$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean:			clean
				make fclean -C ./libft
				$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re:				fclean all

.PHONY:			all clean fclean re
