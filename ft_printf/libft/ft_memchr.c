/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 18:22:26 by yizhang       #+#    #+#                 */
/*   Updated: 2022/10/31 09:12:45 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
