/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 14:22:15 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/21 15:56:58 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(t_game *all);
void	check_error(t_game *all, char *map);
void	check_wall(t_game *all);
void	free_smap(t_game *all);

void	free_smap(t_game *all)
{
	int	i;

	i = 0;
	while (all->s_map[i])
	{
		free(all->s_map[i]);
		i++;
	}
	if (all->s_map)
		free(all->s_map);
}

void	print_error(t_game *all)
{
	ft_printf("Error\n");
	free_smap(all);
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
			if (x == 0 && all->s_map[y][x] != '1')
				print_error(all);
			if (y == 0 && all->s_map[y][x] != '1')
				print_error(all);
			if (y == all->colums - 1 && all->s_map[y][x] != '1')
				print_error(all);
			if (x == all->rows - 1 && all->s_map[y][x] != '1')
				print_error(all);
			x++;
		}
		y++;
	}
}

void	check_error(t_game *all, char *map)
{
	int	y;

	y = 0;
	all->s_map = ft_split(map, '\n');
	count_rows_colums(all->s_map, all);
	count_c_e_p(all->s_map, all);
	if (all->c_count < 1 || all->e_count != 1 || all->p_count != 1)
		print_error(all);
	while (all->s_map[y])
	{
		if (ft_strlen(all->s_map[y]) != all->rows)
			print_error(all);
		y++;
	}
	check_wall(all);
	check_path(all);
	all->s_map = ft_split(map, '\n');
	count_c_e_p(all->s_map, all);
}