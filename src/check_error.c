/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 14:22:15 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/17 15:26:54 by yizhang       ########   odam.nl         */
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
	count_rows_colums(all->s_map, all);
	count_c_e(all->s_map, all);
	if (all->c_count > 1 || all->e_count != 1 || all->p_count != 1)
		print_error();
}
