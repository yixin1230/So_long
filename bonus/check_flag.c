/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_flag.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:28:38 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/26 18:38:57 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_flag(t_game *all, char *c1, char *c2);
void	check_flag_utils(t_game *all);

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
			check_flag_utils(all);
			if (all->c_count == 0 && *c2 == 'e')
				all->win_lose = 1;
			if (*c2 != 'E')
			{
				*c2 = 'P';
				*c1 = '0';
			}
			return (1);
		}
		if (*c2 == 'X')
			all->win_lose = -1;
	}
	return (0);
}

void	check_flag_utils(t_game *all)
{
	all->move_count++;
	ft_printf("move:%i\n", all->move_count);
	all->old_text = all->text;
	put_sting(all);
	delete_string(all);
}
