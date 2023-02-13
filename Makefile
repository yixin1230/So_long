# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yizhang <yizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/25 18:15:26 by yizhang       #+#    #+#                  #
#    Updated: 2023/02/13 13:15:34 by yizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = game
CC = gcc
FLAG = -Werror -Wall -Wextra
LINKS = -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
LIB = MLX42/libmlx42.a
LIBFT = libft/libft.a
SRC = main.c read_map.c count_rows_colums.c load_assets.c
OBJ = ${SRC:%.c=%.o}


all: ${NAME}

${NAME}: ${SRC} ${LIB} ${LIBFT}
	@${CC} ${FLAG} ${LIB} ${LIBFT} ${LINKS} ${SRC} -o ${NAME}

${LIB}:
	@make -C MLX42

${LIBFT}:
	@make bonus -C libft

clean:
	@make clean -C MLX42
	@make clean -C libft
	@rm -rf ${OBJ}

fclean: clean
	@make fclean -C MLX42
	@make fclean -C libft
	@rm -rf ${NAME}

re:fclean all
