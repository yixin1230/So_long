/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation_banana.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 13:42:38 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/26 15:22:15 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_banana(t_game *all);
void	banana_move(t_game *all);

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
	speed = 90;
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
					if(all->s_map[y][x + 1] == '0' || all->s_map[y][x + 1] == 'P')
					{
						if (all->s_map[y][x + 1] == 'P')
						{
							ft_printf("you lose\n");
							all->win_lose = -1;
						}
						all->s_map[y][x + 1] = 'X';
						all->s_map[y][x] = '0';
						return ;
					}
					else// if ((all->s_map[y][x - 1] == '0' && all->s_map[y][x + 1] != '0') || all->s_map[y][x - 1] == 'P')
					{
						if (all->s_map[y][x - 1] == 'P')
						{
							ft_printf("you lose\n");
							all->win_lose = -1;
						}
						all->s_map[y][x - 1] = 'X';
						all->s_map[y][x] = '0';
						return ;
					}
				}
			}
		}
	}
}
