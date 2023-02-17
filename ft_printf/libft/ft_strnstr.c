/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 18:21:57 by yizhang       #+#    #+#                 */
/*   Updated: 2022/10/31 09:23:31 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*n;

	hay = (char *)haystack;
	n = (char *)needle;
	if (*n == 0)
		return (hay);
	while (*hay && len)
	{
		if (ft_strlen(needle) > len)
			return (NULL);
		if (ft_strncmp(hay, n, ft_strlen(needle)) == 0)
			return (hay);
		hay++;
		len--;
	}
	return (NULL);
}
