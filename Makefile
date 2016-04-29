# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guiricha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/12 17:14:52 by guiricha          #+#    #+#              #
#    Updated: 2016/01/18 19:56:35 by guiricha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_algo.c \
		   ft_check_list.c \
		   ft_data_to_list.c \
		   ft_fillit.c \
		   ft_list_to_tetri.c \
		   ft_lstadd.c \
		   ft_lstnew.c \
		   ft_memalloc.c \
		   ft_memcpy.c \
		   ft_memset.c \
		   ft_putchar.c \
		   ft_putstr.c \
		   ft_strdup.c \
		   ft_strlen.c \
		   ft_strnew.c \
		   ft_update_tab.c \
		   ft_utilities.c \
		   ft_test.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_DIR = sources/
OBJ_DIR = objects/
NAME = fillit
CC = gcc
CFLAGS = -Werror -Wextra -Wall
SOURCEDIR = $(addprefix $(SRC_DIR),$(SRC_NAME))

all: $(NAME)

$(NAME):
	mkdir objects
	$(CC) $(CFLAGS) -c $(SOURCEDIR)
	mv $(OBJ_NAME) ./objects/
	$(CC) $(CFLAGS) $(OBJ_DIR)*.o -o $(NAME)

clean:
	rm -f $(OBJ_DIR)*.o
	rm -rf ./objects/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
