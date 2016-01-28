# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015\11/26 11:16:13 by jmaiquez          #+#    #+#              #
#    Updated: 2016/01/22 13:00:43 by jmaiquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c \
	  new.c \
	  parse.c \
	  key.c \
	  point.c \
	  line.c

FLAG = -g -Wall -Werror -Wextra

$(NAME):
	@echo "===========[ \x1b[31mF \x1b[32mD \x1b[34mF \x1b[37m]==========="
	@echo ""
	@echo "\x1b[31m > \x1b[32mCompilation Libft ...\x1b[37m"
	@cd libft && make re && cd ..
	@echo "\x1b[31m > \x1b[32mCompilation F D F ...\x1b[37m"
	@gcc $(FLAG) $(SRC) -o $(NAME) -L. libft/libft.a -I./incs/ -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit
	@echo "\x1b[31m > \x1b[34mCompilation terminée\x1b[37m"
	@echo ""

all: $(NAME)

clean:
	@cd libft && make clean && cd ..
	@rm -f $(OBJ)

fclean: clean
	@cd libft && make fclean && cd ..
	@rm -f $(NAME)

launch: re
	@cd libft && make re && cd ..
	@echo "\x1b[31m > \x1b[34m /!\ LAUNCH FDF /!\ \x1b[37m"
	@./fdf
	@echo ""
	@echo "==============================="

re: fclean all
