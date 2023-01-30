/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 18:33:30 by yizhang       #+#    #+#                 */
/*   Updated: 2023/01/27 17:05:55 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* 
1.map
2.(x,y)
3.read map and find pacman inside map,return the (x,y)
4.change (x,y) to a new place, and delete the old one 
5.move the pacman based on the key"w.a.s.d",+-(x,y)
6.check the illegal moves,where is wall ,ghost
7.set how to win the game,eat all the pills,count pills"*/

int32_t	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(1920, 1920, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
