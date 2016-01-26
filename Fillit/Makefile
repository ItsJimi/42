# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015\11/26 11:16:13 by jmaiquez          #+#    #+#              #
#    Updated: 2016/01/07 15:07:11 by jmaiquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
	  define_patterns.c \
	  define_result.c \
	  resolve.c \
	  checks.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_strlen.c

FLAG = -Wall -Werror -Wextra

$(NAME):
	@echo "===========[ \x1b[31mF \x1b[32mI \x1b[34mL \x1b[35mL \x1b[36mI \x1b[33mT \x1b[37m]==========="
	@echo ""
	@echo "\x1b[31m > \x1b[32mCompilation Fillit ...\x1b[37m"
	@gcc $(FLAG) $(SRC) -o $(NAME)
	@echo "\x1b[31m > \x1b[34mCompilation terminée\x1b[37m"
	@echo ""
	@echo "====================================="

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
