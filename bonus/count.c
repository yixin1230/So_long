/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 10:41:47 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/27 09:23:22 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_c_e(char **str, t_game *all);
void	count_rows_colums(char **str, t_game *all);
void	check_count_c_e_p(char c, t_game *all);

void	count_rows_colums(char **str, t_game *all)
{
	int	x;

	x = 0;
	if (!all || !*str)
		return ;
	while (str[x])
		x++;
	all->rows = ft_strlen(str[0]);
	all->colums = x;
	all->move_count = 0;
	all->e_count = 0;
}

void	check_count_c_e_p(char c, t_game *all)
{
	if (c == 'C')
		all->c_count++;
	if (c == 'E')
		all->e_count++;
	if (c == 'P')
		all->p_count++;
	if (c != 'P' && c != 'E' && c != 'C' && c != 'X'
		&& c != '0' && c != '1' && c != '\n')
		print_error(all, "char error\n");
}

void	count_c_e_p(char **str, t_game *all)
{
	int	x;
	int	y;

	y = -1;
	all->c_count = 0;
	all->e_count = 0;
	all->p_count = 0;
	while (++y < all->colums)
	{
		x = -1;
		while (++x < all->rows)
		{
			check_count_c_e_p(str[y][x], all);
			if (str[y][x] == 'E')
			{
				all->e_x = x;
				all->e_y = y;
			}
		}
	}
}
