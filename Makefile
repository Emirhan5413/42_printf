NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_printf.c \
		print_char.c \
		print_string.c \
		print_int.c \
		print_unsigned.c \
		print_hex.c \
		print_pointer.c \
		utils.c

OBJS = $(FILES:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re