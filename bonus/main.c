/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 18:33:30 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/26 17:40:21 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <string.h>

static void	leaks(void)
{
	system("leaks -q so_long");
}

void	hook(void *all)
{
	t_game	*tmp;

	tmp = all;
	
	print_all_map(tmp);
	banana_move(tmp);
	tmp->loop++;
}

int32_t	main(int argc, char **argv)
{
	char	*map;
	t_game	all;

	atexit(leaks);
	if (argc != 2)
		exit (1);
	map = read_map(argv[1]);
	check_error(&all, map);
	free(map);
	all.mlx = mlx_init(64 * all.rows, 64 * all.colums + 80, "Game", 1);
	if (!all.mlx)
		exit(1);
	all.loop = 0;
	all.b_right = 0;
	all.b_left = 0;
	all.b_nb = 0;
	load_assets(&all);
	put_str_on_window(&all);
	mlx_loop_hook(all.mlx, &hook, &all);
	mlx_key_hook(all.mlx, &key_hook_move, &all);
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);
	return (0);
}
