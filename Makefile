SRC		= server.c client.c

OBJS	= $(SRC:.c=.o)

FLAGS	= -Wall -Werror -Wextra

PRINTF	= ft_printf/libftprintf.a

all: server client

bonus: server client

server: server.o 
	gcc $(FLAGS) -o $@ $< $(PRINTF)

client: client.o 
	gcc $(FLAGS) -o $@ $< $(PRINTF)

.c.o:
	@make -C printf
	gcc -c $(FLAGS) $?

clean:
	rm -f $(OBJS) $(BOJS)
	@make clean -C printf

fclean: clean
	rm -f server client
	@rm -f $(PRINTF)

re: fclean all

n:
	norminette
