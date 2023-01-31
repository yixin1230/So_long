# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yizhang <yizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/25 18:15:26 by yizhang       #+#    #+#                  #
#    Updated: 2023/01/31 13:41:21 by yizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = game
CC = gcc
FLAG = -Werror -Wall -Wextra
LINKS = -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
LIB = MLX42/libmlx42.a
SRC = main.c read_map.c
OBJ = ${SRC:%.c=%.o}


all: ${NAME}

${NAME}: ${SRC}
	@${CC} ${FLAG} ${LIB} ${LINKS} ${SRC} -o ${NAME}

${LIB}:
	@${MAKE} -C MLX42

clean:
	@clean -C MLX42
	@rm -rf ${OBJ}

fclean: clean
	@fclean -C MLX42
	@rm -rf ${NAME}

re:fclean all
