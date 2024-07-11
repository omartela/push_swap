# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 14:12:36 by omartela          #+#    #+#              #
#    Updated: 2024/07/08 15:37:44 by omartela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/operations.c \
	  src/operations_2.c \
	  src/utilities.c \
	  src/error_handling.c \
	  src/linkedliststack.c \
	  src/init_linkedliststack.c \
	  src/algorithm.c \
	  src/main.c

OBJS = $(SRC:.c=.o)

CC = cc
LIBS = src/libft/libft.a src/ft_printf/libftprintf.a
CFLAGS = -g -Wall -Wextra -Werror -I$(INCLUDES)
INCLUDES = includes/

LIBFT_DIR = src/libft
FT_PRINTF_DIR = src/ft_printf

all: libft ft_printf $(NAME)

libft:
	@make -C $(LIBFT_DIR) && make -C $(LIBFT_DIR) bonus

ft_printf:
	@make -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft
