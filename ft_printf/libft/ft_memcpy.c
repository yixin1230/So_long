/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 18:26:29 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/04 18:26:29 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{	
	size_t		i;
	char		*tmp_dst;
	const char	*tmp_src;

	i = 0;
	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	return (dst);
}
