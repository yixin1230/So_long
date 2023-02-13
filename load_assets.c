/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_assets.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 12:19:02 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/13 15:46:44 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

mlx_image_t	*xpm_to_image(mlx_t *mlx, char	*img_path);
void	load_assets(t_game *all);
void	print_image(t_game *all, int x, int y);
void	print_all_map(t_game *all);
int	open_image(char	*str);

int	open_image(char	*str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (1);
}

mlx_image_t	*xpm_to_image(mlx_t *mlx, char *img_path)
{
	xpm_t			*xpm;
	mlx_texture_t	texture;
	mlx_image_t		*image;

	if (open_image(img_path) == -1)
		return (NULL);
	xpm = mlx_load_xpm42(img_path);
	if (!xpm)
		return (NULL);
	texture = xpm->texture;
	image = mlx_texture_to_image(mlx, &texture);
	if (!image)
		return (NULL);
	mlx_delete_xpm42(xpm);
	return (image);
}

void	load_assets(t_game *all)
{
	all->assets.banana = xpm_to_image(all->mlx, "assets/banana.xpm42");
	all->assets.home = xpm_to_image(all->mlx, "assets/home.xpm42");
	all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo.xpm42");
	all->assets.rice_ball = xpm_to_image(all->mlx, "assets/rice_ball.xpm42");
	all->assets.wall = xpm_to_image(all->mlx, "assets/wall.xpm42");
}

void	print_image(t_game *all, int x, int y)
{
	if (all->s_map[y][x] == '1')
		mlx_image_to_window(all->mlx, all->assets.wall, x * 64, y * 64);
	else if (all->s_map[y][x] == 'C')
		mlx_image_to_window(all->mlx, all->assets.rice_ball, x * 64, y * 64);
	else if (all->s_map[y][x] == 'E')
		mlx_image_to_window(all->mlx, all->assets.home, x * 64, y * 64);
	else if (all->s_map[y][x] == 'P')
		mlx_image_to_window(all->mlx, all->assets.noonoo, x * 64, y * 64);
}

void	print_all_map(t_game *all)
{
	int	x;
	int y;

	y = 0;
	while (y < all->colums)
	{
		x = 0;
		while (x < all->rows)
		{
			print_image(all, x, y);
			x++;
		}
		y++;
	}
}
