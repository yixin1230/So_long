/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/29 15:00:50 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/13 15:54:35 by yizhang       ########   odam.nl         */
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
	mlx_t		*mlx;
	char		**s_map;
	t_assets	assets;
	t_assets	old_assets;
	int		rows;
	int		colums;
	int		screen_x;
	int		screen_y;
}t_game;

char		*read_map(char *map_path);
void		count_rows_colums(char **str, t_game *all);
mlx_image_t	*xpm_to_image(mlx_t *mlx, char	*img_path);
void		load_assets(t_game *all);
void		print_image(t_game *all, int x, int y);
void		print_all_map(t_game *all);
int			open_image(char	*str);

#endif
