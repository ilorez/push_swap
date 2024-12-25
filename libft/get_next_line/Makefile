SRCS = get_next_line.c \
			 get_next_line_utils.c
B_SRCS = get_next_line_bonus.c \
				get_next_line_utils_bonus.c

OBJS = $(SRCS:%.c=%.o) 
B_OBJS = $(B_SRCS:%.c=%.o) 

INCLUDES_DR = ../includes
FLAGS = -Wall -Wextra -Werror -g  -I${INCLUDES_DR}
NAME = get_next_line.a
B_NAME = get_next_line_bonus.a
CC = cc
AR = ar rc
RM = rm -f

all: mandatory

mandatory: ${NAME}

bonus: ${B_NAME}

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	
$(B_NAME): $(B_OBJS)
	$(AR) $(B_NAME) $(B_OBJS)

objs: ${OBJS} 

b_objs: ${B_OBJS}

%.o: %.c
	$(CC) $(FLAGS)  -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re objs b_objs mandatory bonus
