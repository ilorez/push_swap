SRCS= create_stack.c \
			get_pos_of.c \
			push_swap.c \
			sort_more.c \
			sort_stack.c \
			debugging.c \
			lst_oprs/oprs.c \
			push_swap_utils.c \
			sort_more_utils.c \
			sort_three.c \
			error_manager.c \
			operations.c \
			run_oprations_lst.c \
			sort_more_utils_two.c \
			sort_two.c

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror -g

LIBFT_DR = ../libft

NAME = push_swap
BUILD_DR = ../build
INCLUDES_DR = ../libft/includes
CC = cc
AR = ar rc
RM = rm -f

all: build

build: $(OBJS) make_libft
	$(CC) $(FLAGS) $(OBJS) -I. -I$(INCLUDES_DR) -L$(LIBFT_DR) -lft -o $(BUILD_DR)/$(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I. -I$(INCLUDES_DR) -c $< -o $@

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
