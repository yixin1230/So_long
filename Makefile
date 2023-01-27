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
LINKS = -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
LIB = MLX42/libmlx42.a
SRC = main.c
OBJ = ${SRC:%.c=%.o}


all: ${NAME}

${NAME}: ${SRC}
		${CC} ${FLAG} ${LIB} ${LINKS} ${SRC} -o ${NAME}

${LIB}:
	${MAKE} -C MLX42

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re:fclean all
