/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 17:53:47 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/17 13:56:13 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *all);
void	move_down(t_game *all);
void	move_left(t_game *all);
void	move_right(t_game *all);
int		check_flag(t_game *all, char *c1, char *c2);

void	move_up(t_game *all)
{
	int	x;
	int	y;

	y = -1;
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

int	check_flag(t_game *all, char *c1, char *c2)
{
	if (*c1 == 'P')
	{
		if (*c2 == '0' || *c2 == 'C' || *c2 == 'E' || *c2 == 'e')
		{
			if (*c2 == 'C')
				all->c_count--;
			if (all->c_count == 0)
				all->s_map[all->e_y][all->e_x] = 'e';
			if (all->c_count == 0 && *c2 == 'e')
				exit(0);
			if (*c2 != 'E')
			{
				all->move_count++;
				ft_printf("move:%i\n", all->move_count);
				*c2 = 'P';
				*c1 = '0';
			}
			return (1);
		}
	}
	return (0);
}
