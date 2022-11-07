NAME = so_long

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

SRC = src/input.c \
		src/errors.c \
		src/utils.c \
		src/graphics.c \
		src/map.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		main.c

LIB = libft/libft.a mlx/libmlx.a -framework OpenGL -framework AppKit

MINILIBX = mlx/

LIBFT = libft/

OBJ = *.o

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MINILIBX)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(MAKE) clean -C $(MINILIBX)
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJ)
	rm -rf $(NAME)

fclean: clean

re: fclean all

map1: re
	./so_long map/map1.ber

map2: re
	./so_long map/map2.ber

git: fclean
	git add *
	git commit 
	git push