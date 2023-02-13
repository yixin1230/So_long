/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 18:33:30 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/13 17:43:58 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <string.h>
/* 
1.map,read map.$
2.(x,y),use split to add xand y.$
3.read map and find pacman inside map,return the (x,y)
4.change (x,y) to a new place, and delete the old one 
5.move the pacman based on the key"w.a.s.d",+-(x,y)
6.check the illegal moves,where is wall ,ghost
7.set how to win the game,eat all the pills,count pills
8.main loop
9.moving the ghosts in all possible directions,find ghosts will find all the ghosts and return.
10.improving the user interface
*/

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
		tmp->assets.noonoo->instances[0].y -= 5;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_S))
		tmp->assets.noonoo->instances[0].y += 5;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_A))
		tmp->assets.noonoo->instances[0].x -= 5;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_D))
		tmp->assets.noonoo->instances[0].x += 5;
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
