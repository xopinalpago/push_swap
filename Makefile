# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 13:00:01 by rmeriau           #+#    #+#              #
#    Updated: 2023/06/14 10:07:12 by rmeriau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = push_swap
SOURCES = ./src/ft_check_params.c ./src/ft_push_swap.c ./src/ft_operations.c ./src/ft_build_list.c \
			./src/ft_utils.c ./src/ft_sort.c ./src/ft_help_sort.c ./src/ft_print_op.c ./src/ft_pos.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJECTS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJECTS) ./libft/libft.a -o $@

clean:
	$(RM) $(OBJECTS)
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	$(RM) ./libft/libft.a
	$(RM) push_swap

re: fclean all