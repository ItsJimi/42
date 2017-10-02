# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 09:58:33 by jmaiquez          #+#    #+#              #
#    Updated: 2017/10/02 10:22:48 by jmaiquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra
NAME = megaphone

all: $(NAME)

$(NAME):
	clang++ $(FLAG) $(NAME).cpp -c
	clang++ $(FLAG) $(NAME).o -o $(NAME)

clean:
	rm -f $(NAME).o

fclean: clean
	rm -f $(NAME)

re: fclean all