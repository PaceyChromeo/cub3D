NAME = cub3D
CC = gcc
INC = inc/cub3d.h \
      mlx/mlx.h
FLAGS = -Wall -Werror -Wextra
LIB_NAME = cub3D.a
SRC = ${addprefix srcs/,	color.c \
							debug.c \
							file.c \
							free_stuffs.c \
							main.c \
							map.c \
							texture.c \
							tab.c}

OBJ = ${SRC:.c=.o}

UNAME = ${shell uname -s}
ifeq (${UNAME}, Linux)
	LIB_MLX = -Lmlx_linux/ -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	INC_MLX = -I/usr/include -Imlx_linux -O3
endif
ifeq (${UNAME}, Darwin)
	LIB_MLX = -lmlx -framework OpenGL -framework AppKit
	INC_MLX = -Imlx
endif

%o:%c
	@printf "Please wait...\r"
	@${CC} -Xlinker --verbose ${FLAGS} ${INC_MLX} -c $< -o $@
all: ${NAME}

${NAME}: ${OBJ}
	@make -C libft/
	@mv libft/libft.a cub3D.a
	@ar rcs $(LIB_NAME) $(OBJ)
	@${CC} -g ${LIB_MLX} ${LIB_NAME} -o ${NAME} $?
	@printf "${NAME} created\n"
clean:
	@make -C libft/ clean
	@rm -rf ${OBJ} ${LIB_NAME}
	@printf "OBJ deleted\n"
fclean: clean
	@rm -rf ${NAME}
	@printf "${NAME} deleted\n"

re:	fclean all
