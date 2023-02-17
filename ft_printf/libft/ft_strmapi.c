/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 16:22:58 by yizhang       #+#    #+#                 */
/*   Updated: 2022/10/31 09:22:50 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*ret;

	i = 0;
	len = ft_strlen(s);
	if (!s || !f)
		return (NULL);
	ret = ft_calloc (len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	else
	{
		while (i < len)
		{
			ret[i] = f(i, s[i]);
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
