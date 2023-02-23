/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_assets.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 12:19:02 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/23 13:17:42 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_assets(t_game *all);
void	delete_old_assets(t_game *all);
void	enemy_animation(t_game *all);

void	load_assets(t_game *all)
{
	all->assets.home = xpm_to_image(all->mlx, "assets/come.xpm42");
	if (all->move_d == 'w')
		animation_noonoo_w(all);
	else if (all->move_d == 'd')
		animation_noonoo_d(all);
	else if (all->move_d == 'a')
		animation_noonoo_a(all);
	else
		animation_noonoo_s(all);
	all->assets.rice_ball = xpm_to_image(all->mlx, "assets/rice_ball.xpm42");
	all->assets.wall = xpm_to_image(all->mlx, "assets/wall.xpm42");
	all->assets.open_home = xpm_to_image(all->mlx, "assets/home.xpm42");
	animation_banana(all);
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
