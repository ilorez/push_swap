# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/25 16:09:52 by znajdaou          #+#    #+#              #
#    Updated: 2024/12/27 11:38:48 by znajdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c bonus
vpath %.c srcs
vpath %.c utils

BUILD_DR = ./build
NAME = push_swap
BONUS_NAME = checker

LIBFT_DR = ./libft

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
INCLUDES_DRS = -I./includes -I./libft/includes
CC = cc
AR = ar rc
RM = rm -f

SRCS= get_pos_of.c \
			push_swap.c \
			sort_more.c \
			sort_stack.c \
			push_swap_utils.c \
			sort_more_utils.c \
			sort_three.c \
			sort_more_utils_two.c \
			run_operations_lst.c \
			sort_two.c

UTILS_SRCS= create_stack.c \
			debugging.c \
			oprs.c \
			general_utils.c \
			error_manager.c \
			operations.c \
			run_type.c

BONUS_SRCS= checker.c \
			get_type.c

OBJS = $(SRCS:%.c=%.o)
UTILS_OBJS = $(UTILS_SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES_DRS) -c $< -o $@

$(NAME): $(OBJS) $(UTILS_OBJS)
	make -C $(LIBFT_DR)
	$(CC) $(FLAGS) $(OBJS) $(UTILS_OBJS) $(INCLUDES_DRS) $(LIBFT_DR)/libft.a -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(UTILS_OBJS)
	make -C $(LIBFT_DR)
	$(CC) $(FLAGS) $(BONUS_OBJS) $(UTILS_OBJS) $(INCLUDES_DRS) $(LIBFT_DR)/libft.a -o $(BONUS_NAME)

$(BUILD_DR):
	mkdir -p $@

clean:
	$(RM) $(OBJS) $(UTILS_OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DR) fclean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
