NAME=cub3D
FLAGS= -Wall -Werror -Wextra -g -fsanitize=address
SRC= main.c inits.c   key_maping.c \
	src/utils/utils.c \
	src/parsing/ft_epurstr.c src/parsing/map_utils.c src/parsing/map_error.c src/parsing/map.c src/parsing/textures_handling.c src/parsing/map_checks.c src/parsing/map_utils_2.c \
	src/calculations/calc.c src/calculations/colision.c \
	src/rendering/rendering_minimap.c src/rendering/rendering_minimap_2.c \
	
CC = gcc
MLX_PATH = mlx/
MLX_LIB = $(MLX_PATH)libmlx.a
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT_PATH = libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
OBJECTS= $(SRC:.c=.o)
HEADER = includes/cub3D.h

all:  subsystems $(NAME)

%.o: %.c	$(HEADER)
	gcc $(FLAGS) -Imlx -c -o  $@ $<

subsystems:
	make -C $(MLX_PATH) all
	make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	gcc $(FLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME) 

clean : 
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -f *.o

git : fclean
	@read -p "Enter commit message: " commit_message; \
    git add *; \
    git commit -m "$$commit_message"
	git push



fclean : clean
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all re clean fclean git
