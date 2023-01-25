# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yizhang <yizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/25 18:15:26 by yizhang       #+#    #+#                  #
#    Updated: 2023/01/25 18:15:26 by yizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAG = -Werror -Wall -Wextra
OPENGL = OPENGL
MLX = -Imlx
APPKIT = AppKit
NAME = 
SRC = 
OBJ = ${SRC:%.c=%.o}


all: ${NAME}

${NAME}: ${OBJ}
		${CC} ${OBJ} ${MLX} ${MLX} -framework ${OPENGL} -framework ${appkit}

${OBJ}: ${SRC}
		${CC} ${FLAG} ${MLX} -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re:fclean all
