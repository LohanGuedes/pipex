# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguedes <lguedes@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 20:21:22 by lguedes           #+#    #+#              #
#    Updated: 2022/08/24 22:18:17 by lguedes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_PATH = ./srcs/libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS =	./srcs/pipex.c ./srcs/ft_check_params.c ./srcs/ft_getpath.c

CC =		cc
CFLAGS =	-Wall -Wextra -Werror

all:		$(LIBFT)
			$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o pipex

$(LIBFT):
		$(MAKE) -C $(LIBFT_PATH)

$(NAME):	$(LIBFT)
			$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o pipex

clean:
			@$(MAKE) -C $(LIBFT_PATH) clean

fclean:		clean
			@$(MAKE) -C $(LIBFT_PATH) fclean
			@rm -rf pipex

re:			fclean all

.PHONY:		all clean fclean re
