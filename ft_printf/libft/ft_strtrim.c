/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 15:35:48 by yizhang       #+#    #+#                 */
/*   Updated: 2022/10/27 19:26:56 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_findset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;

	first = 0;
	last = ft_strlen(s1) - 1;
	if ((s1[0] == '\0' && set[0] == '\0') || s1[0] == '\0')
		return (ft_calloc(1, sizeof(char)));
	while (ft_findset(s1[first], set) == 1 && s1)
		first++;
	while (ft_findset(s1[last], set) == 1 && s1)
		last--;
	return (ft_substr(s1, first, last - first + 1));
}
