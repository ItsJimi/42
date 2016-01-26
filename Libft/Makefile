# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015\11/26 11:16:13 by jmaiquez          #+#    #+#              #
#    Updated: 2015/12/03 17:24:48 by jmaiquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_bzero.c \
	  ft_strclr.c \
	  ft_memset.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_atoi.c \
	  ft_striter.c \
	  ft_itoa.c \
	  ft_strsplit.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsub.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

$(NAME):
	gcc $(FLAG) -c $(SRC)
	ar rc libft.a $(OBJ)
	ranlib libft.a

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
