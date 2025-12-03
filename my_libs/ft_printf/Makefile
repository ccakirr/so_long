NAME = libftprintf.a

SOURCES = ft_printf.c\
ft_printf_util.c

FLAG = -Wall -Wextra -Werror

OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(OBJ)

re: fclean all

o: re
	@cc $(FLAG) main.c libftprintf.a -o output
	@./output | cat -e
	@rm -rf output
	@rm -rf $(NAME) $(OBJ)
