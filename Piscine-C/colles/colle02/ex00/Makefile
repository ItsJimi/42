# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/25 10:49:54 by mkergosi          #+#    #+#              #
#    Updated: 2015/07/26 23:34:22 by jmaiquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2

SRC = colle00.c \
	colle01.c \
	colle02.c \
	colle03.c \
	colle04.c \
	colle_2.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_strcmp.c \
	put.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
