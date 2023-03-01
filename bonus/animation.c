/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 12:45:56 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/26 18:31:28 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_noonoo_d(t_game *all);
void	animation_noonoo_w(t_game *all);
void	animation_noonoo_a(t_game *all);
void	animation_noonoo_s(t_game *all);

void	animation_noonoo_w(t_game *all)
{
	int	speed;

	speed = 40;
	all->noonoo = all->loop % speed;
	if (all->noonoo >= 4 && all->noonoo < 8)
		all->assets.noonoo = xpm_to_image(all->mlx, "./assets/noonoo_w1.xpm42");
	else if (all->noonoo >= 8 && all->noonoo < 24)
		all->assets.noonoo = xpm_to_image(all->mlx, "./assets/noonoo_w2.xpm42");
	else
		all->assets.noonoo = xpm_to_image(all->mlx, "./assets/noonoo_w3.xpm42");
}

void	animation_noonoo_d(t_game *all)
{
	int	speed;

	speed = 60;
	all->noonoo = all->loop % speed;
	if (all->noonoo >= 0 && all->noonoo < 10)
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_d1.xpm42");
	else if (all->noonoo >= 10 && all->noonoo < 20)
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_d2.xpm42");
	else if (all->noonoo >= 20 && all->noonoo < 30)
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_d3.xpm42");
	else if (all->noonoo >= 30 && all->noonoo < 40)
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_d4.xpm42");
	else if (all->noonoo >= 40 && all->noonoo < 50)
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_d5.xpm42");
	else
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_d6.xpm42");
}

void	animation_noonoo_a(t_game *all)
{
	int	speed;

	speed = 60;
	all->noonoo = all->loop % speed;
	if (all->noonoo >= 0 && all->noonoo < 10)
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_a1.xpm42");
	else if (all->noonoo >= 10 && all->noonoo < 20)
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_a2.xpm42");
	else if (all->noonoo >= 20 && all->noonoo < 30)
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_a3.xpm42");
	else if (all->noonoo >= 30 && all->noonoo < 40)
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_a4.xpm42");
	else if (all->noonoo >= 40 && all->noonoo < 50)
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_a5.xpm42");
	else
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_a6.xpm42");
}

void	animation_noonoo_s(t_game *all)
{
	int	speed;

	speed = 30;
	all->noonoo = all->loop % speed;
	if (all->noonoo >= 0 && all->noonoo < 10)
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_s1.xpm42");
	else if (all->noonoo >= 10 && all->noonoo < 20)
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_s2.xpm42");
	else
		all->assets.noonoo = xpm_to_image(all->mlx, "assets/noonoo_s3.xpm42");
}
