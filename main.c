/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 18:33:30 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/14 17:42:39 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <string.h>

void	lecks(void)
{
	system("lecks -q game");
}


void	hook(void *all)
{
	t_game	*tmp;

	tmp = all;
	print_all_map(tmp);
}

void	key(void *all)
{
	t_game	*tmp;

	tmp = all;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(tmp->mlx);
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_W))
		tmp->assets.noonoo->instances[0].y -= 64;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_S))
		tmp->assets.noonoo->instances[0].y += 64;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_A))
		tmp->assets.noonoo->instances[0].x -= 64;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_D))
		tmp->assets.noonoo->instances[0].x += 64;
}

int32_t	main(int argc, char **argv)
{
	char	*map;
	t_game	all;

	//atexit(lecks);
	if (argc != 2)
		exit (1);
	map = read_map(argv[1]);
	all.s_map = ft_split(map, '\n');
	free(map);
	count_rows_colums(all.s_map, &all);
	all.screen_x = 64 * all.rows;
	all.screen_y = 64 * all.colums;
	all.mlx = mlx_init(all.screen_x, all.screen_y, "so_long", 1);
	if (!all.mlx)
		exit(1);
	load_assets(&all);
	mlx_loop_hook(all.mlx, &hook, &all);
	mlx_loop_hook(all.mlx, &key, &all);
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);
	return (0);
}
