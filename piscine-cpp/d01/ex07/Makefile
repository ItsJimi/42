# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 09:58:33 by jmaiquez          #+#    #+#              #
#    Updated: 2017/10/03 14:44:27 by jmaiquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
FLAG = -Wall -Werror -Wextra
NAME = replace
SRCS = $(shell ls *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $@

%.o: %.c
	$(CC) $(FLAG) $(SRCS) -c -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all test clean fclean re