/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 18:33:30 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/17 10:22:02 by yizhang       ########   odam.nl         */
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
	mlx_key_hook(all.mlx, &key_hook_move, &all);
	int i = 0;
	while (i < 5)
	{
		printf("%s\n",all.s_map[i]);
		i++;
	}
	
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);
	return (0);
}
