NAME = lem-in

CC = gcc

FLAGS = -Wall -Wextra -Werror

LEMIN_S_PATH = lemin_src/
LEMIN_O_PATH = lemin_obj/
LIBPATH = libft/

INC_LIB	= -I libft/inc/
INC 	= -I inc/

LIB 	= libftprintf.a

LEMIN_SRC = lemin.c parsing.c pars_tools.c room_tools.c
LEMIN_OBJ = $(addprefix $(LEMIN_O_PATH), $(LEMIN_SRC:.c=.o))

all: $(LIB) $(NAME)

$(LIB):
	@make -C $(LIBPATH)

$(NAME): $(LEMIN_OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(LEMIN_OBJ) $(LIBPATH)$(LIB)

$(LEMIN_O_PATH)%.o: $(LEMIN_S_PATH)%.c
	@mkdir $(LEMIN_O_PATH) 2> /dev/null || true
	$(CC) $(FLAGS) -o $@ $(INC) $(INC_LIB) -c $<

.PHONY: clean fclean re

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBPATH)

clean:
	@rm -rf $(LEMIN_OBJ)
	@make clean -C $(LIBPATH)

re: fclean all
