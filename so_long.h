/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/29 15:00:50 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/13 12:26:02 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_assets
{
	mlx_image_t	*banana;
	mlx_image_t	*home;
	mlx_image_t	*noonoo;
	mlx_image_t	*rice_ball;
	mlx_image_t	*wall;
}t_assets;

typedef struct s_game
{
	mlx_t	*mlx;
	char	**s_map;
	long	rows;
	long	colums;
	long	screen_x;
	long	screen_y;
}t_game;

char	*read_map(char *map_path);
void	count_rows_colums(char **str, t_game *all);

#endif
