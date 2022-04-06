SERVER = server
SERVERBONUS = server_bonus

SRC = server.c

SRCSERVERBONUS = server_bonus.c

CLIENT = client
CLIENTBONUS = client_bonus

SRC2 = client.c

SRCCLIENTBONUS = client_bonus.c

OBJ = ${SRC:.c=.o}
OBJ2 = ${SRC2:.c=.o}

OBJSERVERBONUS = ${SRCSERVERBONUS:.c=.o}
OBJCLIENTBONUS = ${SRCCLIENTBONUS:.c=.o}

FLAGS = -Wall -Werror -Wextra

CC = gcc

.c.o: ${CC} ${FLAGS} -I minitalk.h -c $< -o ${<:.c=.o}

all: ${OBJ} ${OBJ2}
		$(MAKE) -C ./ftprintf all
		$(CC) $(FLAGS) $(SRC) -o $(SERVER) ftprintf/libftprintf.a
		$(CC) $(FLAGS) $(SRC2) -o $(CLIENT) ftprintf/libftprintf.a

bonus: ${OBJSERVERBONUS} ${OBJCLIENTBONUS}
			$(MAKE) -C ./ftprintf all
			${CC} ${FLAGS} ${SRCSERVERBONUS} -o ${SERVERBONUS} ftprintf/libftprintf.a
			${CC} ${FLAGS} ${SRCCLIENTBONUS} -o ${CLIENTBONUS} ftprintf/libftprintf.a

server: $(OBJ)
			$(MAKE) -C ./ftprintf all
			$(CC) $(FLAGS) $(SRC) -o $(SERVER) ftprintf/libftprintf.a

client:	$(OBJ2)
			$(MAKE) -C ./ftprintf all
			$(CC) $(FLAGS) $(SRC2) -o $(CLIENT) ftprintf/libftprintf.a


clean : 
	$(MAKE) -C ./ftprintf clean
	rm -rf $(OBJ)
	rm -rf $(OBJ2)
	rm -rf $(OBJSERVERBONUS)
	rm -rf $(OBJCLIENTBONUS)

fclean : clean
	$(MAKE) -C ./ftprintf fclean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)
	rm -rf $(SERVERBONUS)
	rm -rf $(CLIENTBONUS)

re : fclean all

.PHONY: all clean fclean re bonus 
