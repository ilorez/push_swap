SRCS= ./push_swap/create_stack.c \
			./push_swap/get_pos_of.c \
			./push_swap/push_swap.c \
			./push_swap/sort_more.c \
			./push_swap/sort_stack.c \
			./push_swap/debugging.c \
			./push_swap/lst_oprs/oprs.c \
			./push_swap/push_swap_utils.c \
			./push_swap/sort_more_utils.c \
			./push_swap/sort_three.c \
			./push_swap/error_manager.c \
			./push_swap/operations.c \
			./push_swap/run_oprations_lst.c \
			./push_swap/sort_more_utils_two.c \
			./push_swap/sort_two.c

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror -g

LIBFT_DR = ./libft

NAME = push_swap

BUILD_DR = ./build
INCLUDES_DRS = -I./includes -I./libft/includes
CC = cc
AR = ar rc
RM = rm -f

all: build

build: $(OBJS) make_libft
	mkdir -p $(BUILD_DR)
	$(CC) $(FLAGS) $(OBJS) $(INCLUDES_DRS) -L$(LIBFT_DR) -lft -o $(BUILD_DR)/$(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES_DRS) -c $< -o $@

make_libft:
	make -C $(LIBFT_DR) all
	make -C $(LIBFT_DR) clean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(BUILD_DR)/$(NAME)
	make -C $(LIBFT_DR) fclean

re: fclean all

.PHONY: all clean fclean re build make_libft
