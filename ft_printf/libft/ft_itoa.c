/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 16:22:37 by yizhang       #+#    #+#                 */
/*   Updated: 2022/10/31 09:41:03 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(int n)
{
	long	i;
	int		count;

	i = n;
	count = 1;
	if (n < 0)
		i = -i;
	while (i > 9)
	{
		i /= 10;
		count++;
	}
	return (count);
}

static char	*digit(long nb, int n, char *c, int len)
{
	while (len)
	{
		if (len <= 1)
			c[len - 1] = nb + '0';
		else
		{
			c[len - 1] = (nb % 10) + '0';
			nb /= 10;
		}
		len--;
	}
	if (n < 0)
		c[len] = '-';
	return (c);
}

char	*ft_itoa(int n)
{
	char	*c;
	long	nb;
	size_t	len;

	nb = (long)n;
	len = count(n);
	if (nb < 0)
	{
		len += 1;
		c = malloc((len + 1) * sizeof(char));
		nb = -nb;
	}
	else
		c = malloc((len + 1) * sizeof(char));
	if (!c)
		return (NULL);
	digit(nb, n, c, len);
	c[len] = '\0';
	return (c);
}
