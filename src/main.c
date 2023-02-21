/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 18:33:30 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/21 09:55:44 by yizhang       ########   odam.nl         */
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
}

int32_t	main(int argc, char **argv)
{
	char	*map;
	t_game	all;

	atexit(leaks);
	if (argc != 2)
		exit (1);
	map = read_map(argv[1]);
	all.s_map = ft_split(map, '\n');
	free(map);
	check_error(&all);
	all.mlx = mlx_init(64 * all.rows, 64 * all.colums, "NooNoo", 1);
	if (!all.mlx)
		exit(1);
	load_assets(&all);
	mlx_loop_hook(all.mlx, &hook, &all);
	mlx_key_hook(all.mlx, &key_hook_move, &all);
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);
	return (0);
}
