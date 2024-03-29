NAME = cub3D
CC = gcc
INC = inc/cub3d.h \
      mlx/mlx.h
FLAGS = -Wall -Werror -Wextra
LIB_NAME = cub3D.a
SRC = ${addprefix srcs/,	color.c \
							convert_rgb.c \
							cub.c \
							debug.c \
							draw.c \
							file.c \
							free_stuffs.c \
							key.c \
							key_arrow.c \
							loop.c \
							main.c \
							map_errors_utils.c \
							map_errors.c \
							map_spaces.c \
							map.c \
							minimap.c \
							mlx_hook.c \
							player.c \
							raycasting.c \
							texture.c \
							tab_utils.c \
							tab.c \
							utils.c \
							wall.c}

OBJ = ${SRC:.c=.o}

LIB_MLX = -lmlx -framework OpenGL -framework AppKit
INC_MLX = -Imlx

%o:%c
	@printf "Please wait...\r"
	@${CC} ${FLAGS} ${INC_MLX} -c $< -o $@
all: ${NAME}

${NAME}: ${OBJ}
	@make -C libft/
	@mv libft/libft.a cub3D.a
	@ar rcs $(LIB_NAME) $(OBJ)
	@${CC} ${LIB_MLX} ${LIB_NAME} -fsanitize=address -o ${NAME} $?
	@printf "${NAME} created\n"
clean:
	@make -C libft/ clean
	@rm -rf ${OBJ} ${LIB_NAME}
	@printf "OBJ deleted\n"
fclean: clean
	@rm -rf ${NAME}
	@printf "${NAME} deleted\n"

re:	fclean all
