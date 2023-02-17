/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_image.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 17:22:00 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/17 12:46:54 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

mlx_image_t	*xpm_to_image(mlx_t *mlx, char	*img_path);
void		print_image(t_game *all, int x, int y);
void		print_all_map(t_game *all);
int			open_image(char	*str);

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

void	print_image(t_game *all, int x, int y)
{
	if (all->s_map[y][x] == '1')
		mlx_image_to_window(all->mlx, all->assets.wall, x * 64, y * 64);
	else if (all->s_map[y][x] == 'C')
		mlx_image_to_window(all->mlx, all->assets.rice_ball, x * 64, y * 64);
	else if (all->s_map[y][x] == 'E')
		mlx_image_to_window(all->mlx, all->assets.home, x * 64, y * 64);
	else if (all->s_map[y][x] == 'e')
		mlx_image_to_window(all->mlx, all->assets.open_home, x * 64, y * 64);
	else if (all->s_map[y][x] == 'P')
		mlx_image_to_window(all->mlx, all->assets.noonoo, x * 64, y * 64);
}

void	print_all_map(t_game *all)
{
	int	x;
	int y;

	y = 0;
	delete_old_assets(all);
	all->old_assets = all->assets;
	load_assets(all);
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
