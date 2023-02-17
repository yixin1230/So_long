/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 14:22:15 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/17 17:19:26 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(void);
void	check_error(t_game *all);
void	check_wall(t_game *all);

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	check_wall(t_game *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->colums)
	{
		x = 0;
		while (x < all->rows)
		{
			if(x == 0 && all->s_map[y][x] != '1')
				print_error();
			if(y == 0 && all->s_map[y][x] != '1')
				print_error();
			if(y == all->colums - 1 && all->s_map[y][x] != '1')
				print_error();
			if(x == all->rows - 1 && all->s_map[y][x] != '1')
				print_error();
			x++;
		}
		y++;
	}
}

void	check_error(t_game *all)
{
	int	y;

	y = 0;
	count_rows_colums(all->s_map, all);
	count_c_e_p(all->s_map, all);
	if (all->c_count > 1 || all->e_count != 1 || all->p_count != 1)
		print_error();
	while(all->s_map[y])
	{
		if(ft_strlen(all->s_map[y]) != all->rows)
			print_error();
		y++;
	}
	check_wall(all);
}
