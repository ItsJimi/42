# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malexand <malexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/27 09:58:56 by malexand          #+#    #+#              #
#    Updated: 2015/07/30 20:29:02 by malexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
NAMELIB = libft.a
SRC = srcs/main.c srcs/solver.c srcs/file_function.c srcs/solver_function.c srcs/ft_putstr.c
OBJ = main.o solver.o file_function.o ft_putstr.o solver_function.o
FLAGS = -Wall -Wextra -Werror
INCLUDE = includes/

all: $(NAME)
	gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(INCLUDE)
$(NAME):
	gcc $(FLAGS) -c $(SRC)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
