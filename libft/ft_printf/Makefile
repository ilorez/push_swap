# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 16:06:17 by znajdaou          #+#    #+#              #
#    Updated: 2024/12/25 15:08:19 by znajdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAN_SRCS = ft_printf.c ft_print_char.c ft_print_str.c \
						ft_print_ptr.c \
						ft_print_nbr.c \
						ft_print_unsigned_nbr.c \
						ft_print_hexa.c 

MAN_OBJS = $(MAN_SRCS:%.c=%.o)

INCLUDE_DR = ../includes/
FLAGS = -Wall -Wextra -Werror -g   -I$(INCLUDE_DR)
NAME = libftprintf.a
CC = cc
AR = ar rc
RM = rm -f

all: $(NAME)

$(NAME): $(MAN_OBJS)
	$(AR) $(NAME) $(MAN_OBJS)

objs: ${MAN_OBJS} 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(MAN_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re objs
