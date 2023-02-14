/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hook_move.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 17:59:12 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/14 18:15:53 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	key_hook_move(mlx_key_data_t key, void *tmp);

void	key_hook_move(mlx_key_data_t keydata, void *tmp)
{
	t_game *all;

	all = tmp;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP))
		move_up(all);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN))
		move_down(all);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT))
		move_right(all);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
		move_left(all);
}