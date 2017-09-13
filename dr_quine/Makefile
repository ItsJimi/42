# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 12:02:38 by jmaiquez          #+#    #+#              #
#    Updated: 2017/09/13 14:06:14 by jmaiquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Colleen
NAME2 = Grace
NAME3 = Sully
FILE	= Colleen.c
FILE2 = Grace.c
FILE3 = Sully.c
SRCS	= $(addprefix ./, $(FILE))
SRCS2	= $(addprefix ./, $(FILE2))
SRCS3	= $(addprefix ./, $(FILE3))
OBJS	= $(SRCS:./Colleen.c=.obj/Colleen.o)
OBJS2	= $(SRCS2:./Grace.c=.obj/Grace.o)
OBJS3	= $(SRCS3:./Sully.c=.obj/Sully.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft
CC		= gcc

all: $(NAME) $(NAME2) $(NAME3)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "\033[90mDone 🍔\033[97m"
.obj/Colleen.o: Colleen.c
	mkdir -p .obj
	@$(CC) -c $< -o $@ $(FLAGS)

$(NAME2): $(OBJS2)
	@$(CC) $(FLAGS) $(SRCS2) -o $(NAME2)
	@echo "\033[90mDone 🍔\033[97m"
.obj/Grace.o: Grace.c
	@$(CC) -c $< -o $@ $(FLAGS)

$(NAME3): $(OBJS3)
	@$(CC) $(FLAGS) $(SRCS3) -o $(NAME3)
	@echo "\033[90mDone 🍔\033[97m"
.obj/Sully.o: Sully.c
	@$(CC) -c $< -o $@ $(FLAGS)

clean:
	@echo "\033[92mDeleting 🍔\033[97m"
	@rm -rf .obj
	@echo "\033[96mClean done 🍔\033[97m"

fclean: clean quine
	@echo "\033[92mDeleting 🍔\033[97m"
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@rm -f $(NAME3)
	@echo "\033[96mFclean Done 🍔\033[97m"

quine: clean
	@rm -rf Sully_*
	@rm -rf Grace_kid.c

run: colleen
	@./colleen

run2: grace
	@./grace
	@cat Grace_kid.c

run3: sully
	@./sully

re: fclean all

.PHONY: all clean fclean re