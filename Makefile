SRC = main.c map_functions.c more_map_functions.c print_functions.c additional_functions.c lem_in.c

OBJ = $(SRC:.c=.o)

LIB = libft.a

LIBPATH = ./libft/

NAME = lem-in

FLAGS = -Wall -Werror -Wextra

all : $(NAME)
$(NAME) :
	@make -C $(LIBPATH)
	@gcc -c $(FLAGS) $(SRC)
	@echo "[Create objects]"
	@gcc -o $(NAME) -g $(FLAGS) $(OBJ) $(LIBPATH)$(LIB)
	@make clean
	@echo "[Create lem-in]"

clean :
	@make clean -C $(LIBPATH)
	@rm -f $(OBJ)
	@echo "[Clean objects]"

fclean : clean
	@make fclean -C $(LIBPATH)
	@rm -f $(NAME)
	@echo "[Clean lem-in]"

re : fclean all