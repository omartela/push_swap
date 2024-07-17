# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 14:12:36 by omartela          #+#    #+#              #
#    Updated: 2024/07/17 09:28:32 by omartela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/operations.c \
	  src/operations_2.c \
	  src/operations_3.c \
	  src/ft_atol.c \
	  src/utilities.c \
	  src/utilities_2.c \
	  src/error_handling.c \
	  src/linkedliststack.c \
	  src/init_linkedliststack.c \
	  src/algorithm.c \
	  src/algorithm_2.c \
	  src/algorithm_3.c \
	  src/main.c

OBJS = $(SRC:.c=.o)

CC = cc
LIBS = src/libft/libft.a
CFLAGS = -g -Wall -Wextra -Werror -I$(INCLUDES)
INCLUDES = includes/

LIBFT_DIR = src/libft

all: libft $(NAME)

libft:
	@make -C $(LIBFT_DIR) && make -C $(LIBFT_DIR) bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft
