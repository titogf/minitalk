NAME = libftprintf.a
SRC = ft_printf.c ft_first_types.c ft_secon_types.c ft_utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)

re: fclean all

n:
	@norminette
