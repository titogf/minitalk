C1	= client

C2	= client_bonus

S1	= server

S2	= server_bonus

CC	= gcc

SRC	= utils.c

OBJS	= $(SRC:.c=.o)

FLAGS	= -Wall -Werror -Wextra

H	= minitalk.h

all: $(C1) $(S1)

$(S1): server.c $(H)
	$(CC) $(FLAGS) server.c $(SRC) -o server
$(C1): client.c $(H)
	$(CC) $(FLAGS) client.c $(SRC) -o client


bonus: $(S2) $(C2)

$(S2): server_bonus.c $(H)
	$(CC) $(FLAGS) server_bonus.c $(SRC) -o server_bonus
$(C2): client_bonus.c $(H)
	$(CC) $(FLAGS) client_bonus.c $(SRC) -o client_bonus

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(C1) $(C2) $(S1) $(S2)

re: fclean all bonus

n:
	norminette
