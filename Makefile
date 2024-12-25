# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/25 16:09:52 by znajdaou          #+#    #+#              #
#    Updated: 2024/12/25 18:30:50 by znajdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= ./push_swap/get_pos_of.c \
			./push_swap/push_swap.c \
			./push_swap/sort_more.c \
			./push_swap/sort_stack.c \
			./push_swap/push_swap_utils.c \
			./push_swap/sort_more_utils.c \
			./push_swap/sort_three.c \
			./push_swap/sort_more_utils_two.c \
			./push_swap/run_operations_lst.c \
			./push_swap/sort_two.c

UTILS_SRCS= ./utils/create_stack.c \
			./utils/debugging.c \
			./utils/lst_oprs/oprs.c \
			./utils/general_utils.c \
			./utils/error_manager.c \
			./utils/operations.c \
			./utils/run_type.c

BONUS_SRCS= ./checker/checker.c \
			./checker/get_type.c

OBJS = $(SRCS:%.c=%.o)
UTILS_OBJS = $(UTILS_SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LIBFT_DR = ./libft

NAME = push_swap
BONUS_NAME = checker

BUILD_DR = ./build
INCLUDES_DRS = -I./includes -I./libft/includes
CC = cc
AR = ar rc
RM = rm -f

all: mandatory bonus

mandatory: $(OBJS) $(UTILS_OBJS) make_libft
	mkdir -p $(BUILD_DR)
	$(CC) $(FLAGS) $(OBJS) $(UTILS_OBJS) $(INCLUDES_DRS) -L$(LIBFT_DR) -lft -o $(BUILD_DR)/$(NAME)

bonus: $(BONUS_OBJS) $(UTILS_OBJS) make_libft
	mkdir -p $(BUILD_DR)
	$(CC) $(FLAGS) $(BONUS_OBJS) $(UTILS_OBJS) $(INCLUDES_DRS) -L$(LIBFT_DR) -lft -o $(BUILD_DR)/$(BONUS_NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES_DRS) -c $< -o $@

make_libft:
	make -C $(LIBFT_DR) all
	make -C $(LIBFT_DR) clean

clean:
	$(RM) $(OBJS) $(UTILS_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(BUILD_DR)/$(NAME)
	$(RM) $(BUILD_DR)/$(BONUS_NAME)
	make -C $(LIBFT_DR) fclean

re: fclean all

.PHONY: all clean fclean re make_libft mandatory bonus
