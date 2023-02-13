/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_rows_colums.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 10:41:47 by yizhang       #+#    #+#                 */
/*   Updated: 2023/02/13 11:14:22 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_rows_colums(char **str, t_game *all)
{
	int	i;

	i = 0;
	if (!all || !*str)
		return ;
	while(str[i])
		i++;
	all->rows = ft_strlen(str[0]);
	all->colums = i;
}