SRC		= server.c client.c ft_printf.c

OBJS	= $(SRC:.c=.o)

FLAGS	= -Wall -Werror -Wextra

all: server client

bonus: server client

server: server.o
   gcc $(FLAGS) -o $@ $<

client: client.o 
   gcc $(FLAGS) -o $@ $<

.c.o:
	gcc -c $(FLAGS) $?

clean:
	rm -f $(OBJS) $(BOJS)

fclean: clean
	rm -f server client

re: fclean all

n:
	norminette
