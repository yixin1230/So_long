# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yizhang <yizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/25 18:15:26 by yizhang       #+#    #+#                  #
#    Updated: 2023/02/23 13:43:18 by yizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long
B_NAME = so_long_bonus
CC = gcc
FLAG = -Werror -Wall -Wextra
LINKS = -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
LIB = MLX42/libmlx42.a
FT_PRINTF = ft_printf/libftprintf.a
SRC_DIR = src/
BONUS_DIR = bonus/
SRC = main.c read_map.c count.c load_assets.c print_image.c move.c key_hook_move.c\
		check_error.c check_path.c
BONUS = main.c read_map.c count.c load_assets.c print_image.c move.c key_hook_move.c\
		check_error.c check_path.c animation.c animation_banana.c
SRC_PATH = ${SRC:%=${SRC_DIR}%}
BONUS_PATH = ${BONUS:%=${BONUS_DIR}%}


all: ${NAME}

bonus:${B_NAME}

${NAME}: ${SRC_PATH} ${LIB} ${FT_PRINTF}
	@${CC} ${FLAG} ${LIB} ${FT_PRINTF} ${LINKS} ${SRC_PATH} -o ${NAME}

${B_NAME}: ${BONUS_PATH} ${LIB} ${FT_PRINTF}
	@${CC} ${FLAG} ${LIB} ${FT_PRINTF} ${LINKS} ${BONUS_PATH} -o ${B_NAME}

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
