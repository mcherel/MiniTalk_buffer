# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcherel- <mcherel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 18:22:08 by mcherel-          #+#    #+#              #
#    Updated: 2022/06/10 16:13:14 by mcherel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SRC_DIR = srcs

OBJ_DIR = .objs

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -L ./$(LIBFT_DIR) -lft

RM = /bin/rm -f

SRCS_CLIENT = $(SRC_DIR)/client.c \

SRCS_SERVER = $(SRC_DIR)/server.c \

OBJS_CLIENT = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/$(NAME_CLIENT).o, $(SRCS_CLIENT))

OBJS_SERVER = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/$(NAME_SERVER).o, $(SRCS_SERVER))

HEAD = -I./include -I./$(LIBFT_DIR)

NAME_CLIENT = client

NAME_SERVER = server

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(NAME_CLIENT):	$(OBJS_CLIENT) $(LIBFT)
				$(CC) $(OBJS_CLIENT) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJS_SERVER) $(LIBFT)
				$(CC) $(OBJS_SERVER) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME_SERVER)

$(LIBFT):
				@make -C $(LIBFT_DIR)

all:			$(NAME_CLIENT) $(NAME_SERVER)

clean:
				@make clean -C $(LIBFT_DIR)
				$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean:			clean
				make fclean -C $(LIBFT_DIR)
				$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re:				fclean all

.PHONY:			all clean fclean re
