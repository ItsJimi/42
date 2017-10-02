# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 09:58:33 by jmaiquez          #+#    #+#              #
#    Updated: 2017/10/02 12:06:10 by jmaiquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra
NAME = phonebook
SRCS = src/*.cpp
OBJ = 

all: $(NAME)

$(NAME):
	clang++ $(FLAG) src/*.cpp inc/*.hpp -c
	clang++ $(FLAG) *.o -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

.PHONY: all $(NAME) clean fclean re

re: fclean all