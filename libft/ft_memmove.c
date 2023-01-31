/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 18:26:15 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/04 18:26:15 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*tmp_src;
	char		*tmp_dst;

	i = 0;
	tmp_src = (const char *)src;
	tmp_dst = (char *)dst;
	if (!tmp_src && !tmp_dst)
		return (NULL);
	if (tmp_src > tmp_dst)
		ft_strcpy(tmp_dst, tmp_src, len);
	else if (tmp_src <= tmp_dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			tmp_dst[i] = tmp_src[i];
		}
	}
	return (dst);
}
