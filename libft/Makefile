NAME = libft.a

SRC =  ft_memcpy.c ft_memmove.c ft_memset.c \
	  ft_strchr.c ft_strcmp.c ft_stpcpy.c \
	  ft_strdup.c ft_strlen.c  \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strsub.c ft_strsplit.c \
	  ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c get_next_line.c


OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
