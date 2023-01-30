# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yizhang <yizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/25 18:15:26 by yizhang       #+#    #+#                  #
#    Updated: 2023/01/27 16:47:19 by yizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = game
CC = gcc
FLAG = -Werror -Wall -Wextra
LINKS = -lglfw3 -lopengl32 -lgdi32
LIB = MLX42/libmlx42.a
SRC = main.c
OBJ = ${SRC:%.c=%.o}


all: ${NAME}

${NAME}: ${SRC}
		${CC} ${FLAG} ${LIB} ${LINKS} ${SRC} -o ${NAME}

${LIB}:
	${MAKE} -C MLX42

clean:
	clean -C MLX42
	rm -rf ${OBJ}

fclean: clean
	fclean -C MLX42
	rm -rf ${NAME}

re:fclean all
