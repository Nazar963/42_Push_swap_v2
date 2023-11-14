# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 15:24:48 by naal-jen          #+#    #+#              #
#    Updated: 2023/11/11 17:48:33 by naal-jen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I./includes
AR = ar cr
# ARF = -rcs
NAME = push_swap.a

SRC = main.c main_helper.c push.c reverse_rotate.c rotate.c swap.c check_if_sorted.c create_list.c create_list_helper.c checks.c cluster_sort.c sort_5.c ft_free.c utils.c computation.c execution.c
# OBJ = $(SRC:.c=.o)
OBJ = main.o main_helper.o push.o reverse_rotate.o rotate.o swap.o check_if_sorted.o create_list.o create_list_helper.o checks.o cluster_sort.o sort_5.o ft_free.o utils.o computation.o execution.o

all: libft $(NAME) compile

libft:
	cd 42_libft && $(MAKE)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -g $(CFLAGS) $(INC) -c $(SRC)

compile:
	$(CC) $(OBJ) -L./42_libft -lft -o push_swap

clean:
	rm -f $(OBJ)
	rm -f push_swap
	cd 42_libft && $(MAKE) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all libft compile clean fclean re