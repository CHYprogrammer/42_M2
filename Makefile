NAME = push_swap
SRC = \
	main.c \
	radix_sort.c \
	sort_short.c \
	set_order_and_check_dup.c \
	init_stack.c \
	my_qsort.c \
	op_funcs.c \
	lst_funcs.c \
	ft_funcs.c
OBJ = $(SRC:.c=.o)
CCW = cc -Wall -Werror -Wextra
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(CCW) $(OBJ) -o $(NAME)

$(OBJ):
	$(CCW) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re