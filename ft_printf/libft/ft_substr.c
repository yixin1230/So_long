/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 08:26:47 by yizhang       #+#    #+#                 */
/*   Updated: 2022/10/31 10:01:33 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)start >= (size_t)ft_strlen(s) || len == 0 || ft_strlen(s) == 0)
	{
		str = ft_calloc(1, sizeof(char));
		return (str);
	}
	if (len > (size_t)ft_strlen(s) - (size_t)start)
		len = (size_t)ft_strlen(s) - (size_t)start;
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
