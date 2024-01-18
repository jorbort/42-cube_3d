NAME=cub3D
FLAGS= -Wall -Werror -Wextra -g -fsanitize=address
SRC= main.c inits.c map.c ft_epurstr.c key_maping.c
CC = gcc
MLX_PATH = mlx/
MLX_LIB = $(MLX_PATH)libmlx.a
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT_PATH = libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
OBJECTS= $(SRC:.c=.o)
HEADER = cub3D.h

all:  subsystems $(NAME)

%.o: %.c	$(HEADER)
	$(CC) $(FLAGS) -Imlx -c -o  $@ $<

subsystems:
	make -C $(MLX_PATH) all
	make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME) 

clean : 
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -f *.o



fclean : clean
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all re clean fclean
