/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 18:25:31 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/04 18:25:31 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*src_tmp;

	i = 0;
	src_tmp = (char *)src;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src_tmp[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
