/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 18:21:52 by yizhang       #+#    #+#                 */
/*   Updated: 2022/10/31 09:24:12 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;

	tmp = NULL;
	while (*s)
	{		
		if (*s == (char)c)
			tmp = s;
		s++;
	}
	if (*s == '\0' && (char)c == '\0')
	{
		tmp = s;
		return ((char *)tmp);
	}
	return ((char *)tmp);
}
