NAME = libftprintf.a

LIBFT = libft

FLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c \
		ft_putchar_cnt.c \
		ft_putstr_cnt.c \
		ft_putptr_cnt.c \
		ft_putnbr_cnt.c \
		ft_putunbr_cnt.c \
		ft_puthnbr_cnt.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
		make -C $(LIBFT) all
		cp ./libft/libft.a $(NAME)
		@ar rcs $(NAME) $(OBJ)
		ranlib ${NAME}

clean :
		@rm -f $(OBJ)
		@echo "Printf OBJ deleted"
		@make clean -C $(LIBFT)

fclean : clean
		@rm -f $(NAME)
		@echo "$(NAME) deleted"
		@make fclean -C $(LIBFT)

testmain : fclean all
		   gcc main.c -L. -lftprintf $(FLAGS) && ./a.out

re: fclean all

.PHONY: all clean fclean re
