/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 17:53:47 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/14 18:19:35 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *all);
void	move_down(t_game *all);
void	move_left(t_game *all);
void	move_right(t_game *all);
//void	check_flag(t_game *all);

void	move_up(t_game *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->colums)
	{
		x = 0;
		while (x < all->rows)
		{
			if (all->s_map[y][x] == 'P')
				all->s_map[y - 1][x] = 'P';
			x++;
		}
		y++;
	}
}

void	move_down(t_game *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->colums)
	{
		x = 0;
		while (x < all->rows)
		{
			if (all->s_map[y][x] == 'P')
				all->s_map[y + 1][x] = 'P';
			x++;
		}
		y++;
	}
}

void	move_left(t_game *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->colums)
	{
		x = 0;
		while (x < all->rows)
		{
			if (all->s_map[y][x] == 'P')
				all->s_map[y][x - 1] = 'P';
			x++;
		}
		y++;
	}
}

void	move_right(t_game *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->colums)
	{
		x = 0;
		while (x < all->rows)
		{
			if (all->s_map[y][x] == 'P')
			{
				all->s_map[y][x + 1] = 'P';
			}
			x++;
		}
		y++;
	}
}

/* void	check_flag(t_game *all)
{

} */
