/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_path.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 12:05:55 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/27 09:22:31 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path_flag(t_game *all, int x, int y);
void	check_path(t_game *all);

void	check_path_flag(t_game *all, int x, int y)
{
	if (all->s_map[y][x] == '1' || x <= 0 || x >= all->rows
		|| y <= 0 || y >= all->colums || all->s_map[y][x] == 'E'
		|| all->s_map[y][x] == 'A' || all->s_map[y][x] == 'c'
		|| all->s_map[y][x] == 'X')
	{
		if (all->s_map[y][x] == 'E')
			all->check_path = 1;
		return ;
	}
	if (all->s_map[y][x] == 'C')
		all->c_count--;
	if (all->s_map[y][x] != 'E' && all->s_map[y][x] != '1')
		all->s_map[y][x] = 'A';
	check_path_flag(all, x, y + 1);
	check_path_flag(all, x, y - 1);
	check_path_flag(all, x + 1, y);
	check_path_flag(all, x - 1, y);
}

void	check_path(t_game *all)
{
	int	x;
	int	y;

	y = 0;
	all->check_path = 0;
	while (y < all->colums)
	{
		x = 0;
		while (x < all->rows)
		{
			if (all->s_map[y][x] == 'P')
			{
				check_path_flag(all, x, y);
				if (all->check_path == 1 && all->c_count == 0)
				{
					free_smap(all);
					return ;
				}
				print_error(all, "path error\n");
				return ;
			}
			x++;
		}
		y++;
	}
}
