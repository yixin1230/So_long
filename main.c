/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 18:33:30 by yizhang       #+#    #+#                 */
/*   Updated: 2023/01/31 17:36:18 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
/* 
1.map,read map.
2.(x,y),use split to add xand y.
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

int32_t	main(int argc, char **argv)
{
	char	*map;
	char	**s_map;

	atexit(lecks);
	if (argc != 2)
		exit (1);
	map = read_map(argv[1]);
	s_map = ft_split(map, '\n');
	free(map);
	//find if all the character are validate(0,1,E,P,C,\n)
	//find how many 'C' inside map, store it in game->c_count
	//find error, not sure if it's really matter

	//find rows and columns
	//find error,about if (x,y) at a wall, not sure if it's really matter
	exit(0);
}
