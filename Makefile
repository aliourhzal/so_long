NAME = so_long
SRC = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ft_split.c map_checker.c
OBJ = get_next_line.o get_next_line_utils.o ft_split.o map_checker.o
MAINSRC = main.c map.c move_it.c
MAINOBJ = main.o map.o move_it.o

all: $(NAME)

$(NAME): $(OBJ) $(MAINOBJ)
	cc -lmlx -framework OpenGL -framework AppKit  $(OBJ) $(MAINOBJ) -o so_long

## for linux
#cc $(OBJ) $(MAINOBJ) libmlx_Linux.a -lmlx -lbsd -lmlx -lXext -lX11 -lm -o so_long

$(OBJ): $(SRC) ./get_next_line/get_next_line.h
	cc -Wall -Werror -Wextra -c $(SRC)

$(MAINOBJ): $(MAINSRC) so_long.h
	cc -Wall -Werror -Wextra -c $(MAINSRC)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all