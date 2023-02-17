/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 10:41:47 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/17 12:36:01 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	count_c_e(char **str, t_game *all);
void	count_rows_colums(char **str, t_game *all);

void	count_rows_colums(char **str, t_game *all)
{
	int	x;

	x = 0;
	if (!all || !*str)
		return ;
	while(str[x])
		x++;
	all->rows = ft_strlen(str[0]);
	all->colums = x;
	all->move_count = 0;
}

void	count_c_e(char **str, t_game *all)
{
	int	x;
	int	y;

	y = -1;
	while (++y < all->colums)
	{
		x = -1;
		while (++x < all->rows)
		{
			if (str[y][x] == 'C')
				all->c_count++;
			if (str[y][x] == 'E')
			{
				all->E_x = x;
				all->E_y = y;
			}
		}
	}
}