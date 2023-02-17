/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 14:22:15 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/17 16:01:24 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(void);
void	check_error(t_game *all);

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	check_error(t_game *all)
{
	int	y;

	y = 0;
	count_rows_colums(all->s_map, all);
	count_c_e(all->s_map, all);
	if (all->c_count > 1 || all->e_count != 1 || all->p_count != 1)
		print_error();
	while(all->s_map[y])
	{
		if(ft_strlen(all->s_map[y]) != all->rows)
			print_error();
		y++;
	}
}
