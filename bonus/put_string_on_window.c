/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_string_on_window.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 14:01:03 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/26 15:19:34 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_str_on_window(t_game *all);
void	put_sting(t_game *all);
void	delete_string(t_game *all);

void	put_str_on_window(t_game *all)
{
	all->text.move_s = mlx_put_string(all->mlx, "Moves:", 4, all->colums * 64 + 10);
	all->text.c_s = mlx_put_string(all->mlx, "collections you need:", 4, all->colums * 64 + 30);
}

void	put_sting(t_game *all)
{
	char	*str_move;
	char	*str_c;

	str_move = ft_itoa(all->move_count);
	str_c = ft_itoa(all->c_count);
	all->text.move_s = mlx_put_string(all->mlx, "Moves:", 4, all->colums * 64 + 10);
	all->text.c_s = mlx_put_string(all->mlx, "collections you need:", 4, all->colums * 64 + 30);
	all->text.move_nb =  mlx_put_string(all->mlx, str_move, 100, all->colums * 64 + 10);
	all->text.c_nb =  mlx_put_string(all->mlx, str_c, 250, all->colums * 64 + 30);
	if (all->win_lose == 1)
		all->text.win_lose = mlx_put_string(all->mlx, "You win!", 4, all->colums * 64 + 60);
	else if (all->win_lose == -1)
		all->text.win_lose = mlx_put_string(all->mlx, "You lose!", 4, all->colums * 64 + 60);
	free(str_move);
	free(str_c);
}

void	delete_string(t_game *all)
{
	mlx_delete_image(all->mlx, all->old_text.move_nb);
	mlx_delete_image(all->mlx, all->old_text.c_nb);
	mlx_delete_image(all->mlx, all->old_text.move_s);
	mlx_delete_image(all->mlx, all->old_text.c_s);
	if (all->win_lose == 1 || all->win_lose == -1)
		mlx_delete_image(all->mlx, all->old_text.win_lose);
}