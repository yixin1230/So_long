/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 12:17:53 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/27 08:26:22 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"

char	*read_map(char *map_path)
{
	int		fd;
	int		count;
	char	c;
	char	*map;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Map Error\n");
		exit(0);
	}
	count = 0;
	while (read(fd, &c, 1) == 1)
		count++;
	map = malloc(count + 1);
	if (!map)
		return (NULL);
	close(fd);
	fd = open(map_path, O_RDONLY);
	read(fd, map, count);
	map[count] = '\0';
	close(fd);
	return (map);
}
