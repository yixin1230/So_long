/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 18:22:23 by yizhang       #+#    #+#                 */
/*   Updated: 2022/10/31 09:13:24 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;

	i = 0;
	s1_tmp = (unsigned char *)s1;
	s2_tmp = (unsigned char *)s2;
	if (!s2 && !s1)
		return (0);
	while (n && s1_tmp[i] == s2_tmp[i])
	{
		n--;
		i++;
	}
	if (n == 0)
		return (0);
	return (s1_tmp[i] - s2_tmp[i]);
}
