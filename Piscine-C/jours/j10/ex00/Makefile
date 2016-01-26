# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/21 11:44:51 by jmaiquez          #+#    #+#              #
#    Updated: 2015/07/21 16:35:18 by jmaiquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_C = srcs/ft_putchar.c \
		 srcs/ft_putstr.c \
		 srcs/ft_strcmp.c \
		 srcs/ft_strlen.c \
		 srcs/ft_swap.c

SRCS_H = includes

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS_C) -i $(SRCS_H)
	ar rc $(NAME) *.o

clean:
	rm -f ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

fclean: clean
	rm -f $(NAME)

re: fclean all
