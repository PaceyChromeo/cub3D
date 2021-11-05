NAME = cub3D
CC = gcc
INC = ./inc/cub3d.h
FLAGS = -Wall -Werror -Wextra
LIB_NAME = cub3D.a
SRC = ${addprefix srcs/,	debug_func.c \
							file.c \
							free_stuffs.c \
							main.c \
							map.c \
							texture.c}

OBJ = ${SRC:.c=.o}

%o:%c
	@printf "Please wait...\r"
	@${CC} ${FLAGS} -Imlx -c $< -o $@
all: ${NAME}

${NAME}: ${OBJ}
	@make -C libft/
	@mv libft/libft.a cub3D.a
	@ar rcs $(LIB_NAME) $(OBJ)
	@${CC} -g -lmlx -framework OpenGL -framework AppKit ${LIB_NAME} -o ${NAME} $?
	@printf "${NAME} created\n"
clean:
	@make -C libft/ clean
	@rm -rf ${OBJ} ${LIB_NAME}
	@printf "OBJ deleted\n"
fclean: clean
	@rm -rf ${NAME}
	@printf "${NAME} deleted\n"

re:	fclean all
