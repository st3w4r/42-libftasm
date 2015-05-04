# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/30 14:18:45 by ybarbier          #+#    #+#              #
#    Updated: 2015/03/30 14:18:49 by ybarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a
NAME_TEST = test
PATH_SRC = ./
PATH_OBJ = ./
#PATH_INC = ./libft/includes/


AS = nasm
ASFLAGS = -f macho64 -g
CC = cc
# CFLAGS = -f macho64
# CFLAGS = -Ofast -I $(PATH_INC) -g

LIBS = -L ./ -lfts -g

#HEAD = $(PATH_SRC)ftl.h

SRC =	ft_bzero.s \
		ft_isalpha.s \
		ft_isdigit.s \
		ft_isalnum.s \
		ft_isascii.s \
		ft_isprint.s \
		ft_toupper.s \
		ft_tolower.s \
		ft_puts.s \
		ft_strlen.s \
		ft_strcat.s \
		ft_memset.s \
		ft_memcpy.s \
		ft_strdup.s \
		ft_cat.s \
		ft_strcmp.s \
		ft_putchar.s \
		ft_putchar_fd.s \
		ft_memcmp.s

OBJ = $(addprefix $(PATH_SRC), $(SRC:.s=.o))


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

.PHONY: clean fclean

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

test: $(OBJ) main.c
	$(CC) main.c $(LIBS) -o $(NAME_TEST)

clean_test:
	/bin/rm -f $(NAME_TEST)
