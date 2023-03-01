/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 17:53:47 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/26 18:29:16 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *all);
void	move_down(t_game *all);
void	move_left(t_game *all);
void	move_right(t_game *all);

void	move_up(t_game *all)
{
	int	x;
	int	y;

	y = -1;
	all->move_d = 'w';
	while (++y < all->colums)
	{
		x = -1;
		while (++x < all->rows)
		{
			if (check_flag(all, &all->s_map[y][x], &all->s_map[y - 1][x]) == 1)
				return ;
		}
	}
}

void	move_down(t_game *all)
{
	int	x;
	int	y;

	y = -1;
	all->move_d = 's';
	while (++y < all->colums)
	{
		x = -1;
		while (++x < all->rows)
		{
			if (check_flag(all, &all->s_map[y][x], &all->s_map[y + 1][x]) == 1)
				return ;
		}
	}
}

void	move_left(t_game *all)
{
	int	x;
	int	y;

	y = -1;
	all->move_d = 'a';
	while (++y < all->colums)
	{
		x = -1;
		while (++x < all->rows)
		{
			if (check_flag(all, &all->s_map[y][x], &all->s_map[y][x - 1]) == 1)
				return ;
		}
	}
}

void	move_right(t_game *all)
{
	int	x;
	int	y;

	y = -1;
	all->move_d = 'd';
	while (++y < all->colums)
	{
		x = -1;
		while (++x < all->rows)
		{
			if (check_flag(all, &all->s_map[y][x], &all->s_map[y][x + 1]) == 1)
				return ;
		}
	}
}
