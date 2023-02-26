/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation_banana.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 13:42:38 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/26 18:55:44 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_banana(t_game *all);
void	banana_move(t_game *all);
void	swap_x(t_game *all, char *c1, char *c2, int i);
void	banana_move_utils(t_game *all, int x, int y);

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

void	banana_move(t_game *all)
{
	int	x;
	int	y;
	int	speed;

	y = -1;
	speed = 25;
	all->banana = all->loop % speed;
	if (all->banana == 3)
	{
		while (++y < all->colums)
		{
			x = -1;
			while (++x < all->rows)
			{
				if (all->s_map[y][x] == 'X')
				{
					banana_move_utils(all, x, y);
					return ;
				}
			}
		}
	}
}

void	swap_x(t_game *all, char *c1, char *c2, int i)
{
	if (*c2 == 'P')
		all->win_lose = -1;
	*c2 = 'X';
	*c1 = '0';
	if (i == 1)
	{
		all->b_right = 1;
		all->b_left = 0;
	}
	else if (i == 2)
	{
		all->b_right = 0;
		all->b_left = 1;
	}
}

void	banana_move_utils(t_game *all, int x, int y)
{
	if ((all->s_map[y][x + 1] == '0' && all->s_map[y][x - 1] != '0')
		|| all->s_map[y][x + 1] == 'P')
		swap_x(all, &all->s_map[y][x], &all->s_map[y][x + 1], 1);
	else if ((all->s_map[y][x - 1] == '0' && all->s_map[y][x + 1] != '0')
		|| all->s_map[y][x - 1] == 'P')
		swap_x(all, &all->s_map[y][x], &all->s_map[y][x - 1], 2);
	else if ((all->s_map[y][x - 1] == '0' && all->s_map[y][x + 1] == '0')
		|| all->s_map[y][x - 1] == 'P')
	{
		if (all->b_right == 0 && all->b_left == 0)
			swap_x(all, &all->s_map[y][x], &all->s_map[y][x + 1], 0);
		else if (all->b_right == 0 && all->b_left == 1)
			all->b_nb = x - 1;
		else if (all->b_right == 1 && all->b_left == 0)
			all->b_nb = x + 1;
		swap_x(all, &all->s_map[y][x], &all->s_map[y][all->b_nb], 0);
		return ;
	}
}
