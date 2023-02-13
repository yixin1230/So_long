/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_assets.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 12:19:02 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/13 13:17:21 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*xpm_to_image(mlx_t *mlx, char	*img_path);
void	load_assets(t_game *all);
void	print_image(t_game *all, int x, int y);
void	print_all_map(t_game *all);

mlx_image_t	*xpm_to_image(mlx_t *mlx, char	*img_path)
{
	xpm_t			*xpm;
	mlx_texture_t	texture;
	mlx_image_t		*image;

	xpm = mlx_load_xpm42(img_path);
	texture = xpm->texture;
	image = mlx_texture_to_image(mlx, &texture);
	mlx_delete_xpm42(xpm);
	return (image);
}

void	load_assets(t_game *all)
{
	all->assets.banana = xpm_to_image(all->mlx, "./assets/banana.xpm42");
	all->assets.home = xpm_to_image(all->mlx, "./assets/home.xpm42");
	all->assets.noonoo = xpm_to_image(all->mlx, "./assets/noonoo.xpm42");
	all->assets.rice_ball = xpm_to_image(all->mlx, "./assets/rice_ball.xpm42");
	all->assets.wall = xpm_to_image(all->mlx, "./assets/wall.xpm42");
}

void	print_image(t_game *all, int x, int y)
{
	if (all->s_map[x][y] == '1')
		mlx_image_to_window(all->mlx, all->assets.wall, x * 64, y * 64);
	if (all->s_map[x][y] == 'C')
		mlx_image_to_window(all->mlx, all->assets.rice_ball, x * 64, y * 64);
	if (all->s_map[x][y] == 'E')
		mlx_image_to_window(all->mlx, all->assets.home, x * 64, y * 64);
	if (all->s_map[x][y] == 'P')
		mlx_image_to_window(all->mlx, all->assets.noonoo, x * 64, y * 64);
}

void	print_all_map(t_game *all)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y < all->colums)
	{
		while (x < all->rows)
		{
			print_image(all, x, y);
			x++;
		}
		y++;
	}
}
