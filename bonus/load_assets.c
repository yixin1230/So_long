/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_assets.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 12:19:02 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/23 12:44:16 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_assets(t_game *all);
void	delete_old_assets(t_game *all);
void	enemy_animation(t_game *all);
void	animation_banana(t_game *all);

void	load_assets(t_game *all)
{
	all->assets.home = xpm_to_image(all->mlx, "assets/come.xpm42");
	if (all->move_d == 'w')
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_w1.xpm42");
	else if (all->move_d == 'd')
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_d1.xpm42");
	else if (all->move_d == 'a')
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_a1.xpm42");
	else
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_s1.xpm42");
	all->assets.rice_ball = xpm_to_image(all->mlx, "assets/rice_ball.xpm42");
	all->assets.wall = xpm_to_image(all->mlx, "assets/wall.xpm42");
	all->assets.open_home = xpm_to_image(all->mlx, "assets/home.xpm42");
	animation_banana(all);
}


void	animation_banana(t_game *all)
{
	int	speed;

	speed = 24;
	all->banana = all->loop % speed;
	if (all->banana >= 4 && all->banana < 8)
		all->assets.banana = xpm_to_image(all->mlx, "./assets/banana1.xpm42");
	else if (all->banana >= 12 && all->banana < 16)
		all->assets.banana = xpm_to_image(all->mlx, "./assets/banana2.xpm42");
	else if (all->banana >= 20 && all->banana < 24)
		all->assets.banana = xpm_to_image(all->mlx, "./assets/banana3.xpm42");
	else
		all->assets.banana = xpm_to_image(all->mlx, "./assets/banana2.xpm42");
}

void	delete_old_assets(t_game *all)
{
	mlx_delete_image(all->mlx, all->old_assets.banana);
	mlx_delete_image(all->mlx, all->old_assets.home);
	mlx_delete_image(all->mlx, all->old_assets.noonoo);
	mlx_delete_image(all->mlx, all->old_assets.rice_ball);
	mlx_delete_image(all->mlx, all->old_assets.wall);
	mlx_delete_image(all->mlx, all->old_assets.open_home);
}
