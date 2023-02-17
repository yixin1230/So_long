# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yizhang <yizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/25 18:15:26 by yizhang       #+#    #+#                  #
#    Updated: 2023/02/17 14:56:47 by yizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = game
CC = gcc
FLAG = -Werror -Wall -Wextra
LINKS = -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
LIB = MLX42/libmlx42.a
FT_PRINTF = ft_printf/libftprintf.a
SRC_DIR = src/
SRC = main.c read_map.c count.c load_assets.c print_image.c move.c key_hook_move.c\
		check_error.c
SRC_PATH = ${SRC:%=${SRC_DIR}%}


all: ${NAME}

${NAME}: ${SRC_PATH} ${LIB} ${FT_PRINTF}
	@${CC} ${FLAG} ${LIB} ${FT_PRINTF} ${LINKS} ${SRC_PATH} -o ${NAME}

${LIB}:
	@make -C MLX42

${FT_PRINTF}:
	@make -C ft_printf

clean:
	@make clean -C MLX42
	@make clean -C ft_printf
	@rm -rf ${OBJ}

fclean: clean
	@make fclean -C MLX42
	@make fclean -C ft_printf
	@rm -rf ${NAME}

re:fclean all
