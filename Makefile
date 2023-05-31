# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 13:00:01 by rmeriau           #+#    #+#              #
#    Updated: 2023/05/24 16:36:46 by rmeriau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -f
AR = ar cr
NAME= push_swap.a
SOURCES = ./src/ft_check_params.c ./src/ft_push_swap.c ./src/ft_operations.c ./src/ft_build_list.c

OBJECTS = $(SOURCES:.c=.o)

#build everything
all: $(NAME)

#make libft
LIB:
	make -C ./libft
	cp ./libft/libft.a $(NAME)

#creates a static library
$(NAME): LIB $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) push_swap.a -o push_swap

#removes all *.o files
clean:
	$(RM) $(OBJECTS)
	make clean -C ./libft

#removes all *.o files + libft.a + libmlx.a
fclean: clean
	$(RM) $(NAME)
	$(RM) ./libft/libft.a
	$(RM) push_swap.a
	$(RM) push_swap

#removes all *.o files + libft.a + libmlx.a and rebuild everything
re: fclean all