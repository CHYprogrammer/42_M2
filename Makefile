NAME = push_swap
SRC = \
	src/main.c \
	src/push_swap.c \
	src/operations_utils.c \
	src/push.c \
	src/swap.c \
	src/rotate.c \
	src/rev_rotate.c
OBJ = $(SRC:.c=.o)
CCW = cc -Wall -Werror -Wextra
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ):
	$(CCW) -I inc -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re