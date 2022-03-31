SERVER = server

SRC = server.c \

CLIENT = client

SRC2 = client.c \

OBJ = ${SRC:.c=.o}
OBJ2 = ${SRC2:.c=.o}

FLAGS = -Wall -Werror -Wextra

CC = gcc

.c.o: ${CC} ${FLAGS} -I minitalk.h -c $< -o ${<:.c=.o}

all: $(SERVER) $(CLIENT)
		$(MAKE) -C ./ftprintf all
		$(CC) $(FLAGS) $(SRC) -o $(SERVER) ftprintf/libftprintf.a
		$(CC) $(FLAGS) $(SRC2) -o $(CLIENT) ftprintf/libftprintf.a

$(SERVER) : $(OBJ)
			$(MAKE) -C ./ftprintf all
			$(CC) $(FLAGS) $(SRC) -o $(SERVER) ftprintf/libftprintf.a

$(CLIENT) :	$(OBJ2)
			$(MAKE) -C ./ftprintf all
			$(CC) $(FLAGS) $(SRC2) -o $(CLIENT) ftprintf/libftprintf.a

clean : 
	$(MAKE) -C ./ftprintf clean
	rm -rf $(OBJ)
	rm -rf $(OBJ2)

fclean : clean
	$(MAKE) -C ./ftprintf fclean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)

re : fclean all

.PHONY: all clean fclean re
