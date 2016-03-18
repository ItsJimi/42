# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 12:02:38 by jmaiquez          #+#    #+#              #
#    Updated: 2016/03/18 11:22:46 by jmaiquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
CYA =		\033[36m
STD =		\033[39m

NAME =		wolf3d

LDIR =		./libs/
LIBS =		-lft

IDIR =		./incs/
INCS =		$(shell ls incs/)
INCC =		$(addprefix $(IDIR),$(INCS))

SDIR =		./srcs/
SRCS =		$(shell ls srcs/)
SRCC =		$(addprefix $(SDIR),$(SRCS))

ODIR =		./objs/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

NORM =		$(SRCC) $(INCC) $(EXEC)

FLAG =		-g -Wall -Wextra -Werror -I$(IDIR)

all: $(NAME)

$(NAME): header $(OBCC)
	@echo "  ${BLU}+ Compilation program :${STD} $@"
	@make -C ./libft/
	@gcc $(FLAG) $(OBCC) ./libft/libft.a -I./incs/ -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(ODIR)%.o: $(SDIR)%.c
	@echo "  ${GRE}+ Compilation :${STD} $^"
	@gcc $^ $(FLAG) -c -o $@

header:
	@mkdir -p $(ODIR)
	@echo "${YEL}"
	@echo "   _____             "
	@echo "  |_  (_)_ __ ___ (_)"
	@echo " _  | | | '_ \` _ \| |"
	@echo "| |_| | | | | | | | |"
	@echo " \___/|_|_| |_| |_|_|"
	@echo
	@echo "${STD}"

norme: header
	@echo "${GRE}  Norme${STD}\n"
	@norminette $(NORM)
	@echo "${RED}  \nTotal errors :${STD}" $(shell norminette $(NORM) | grep -v "Norme" | wc -l)

clean: header
	@echo "  ${RED}- Remove objects${STD}"
	@rm -rf $(OBCC)

fclean: clean
	@echo "  ${RED}- Remove $(NAME)${STD}"
	@make -C ./libft/ fclean
	@rm -f $(NAME)

.PHONY: all $(NAME) $(ODIR)%.o header norme clean fclean re

re: fclean all
