/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:05:17 by yizhang       #+#    #+#                 */
/*   Updated: 2022/12/08 14:58:35 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(unsigned int c);
int	ft_putstr(char *s);
int	ft_putptr(uintptr_t p);
int	length(long nb);
int	ft_putint(long nb);

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putchar(unsigned int c)
{
	return (write(1, &c, 1));
}

int	ft_putptr(uintptr_t p)
{
	int		i;
	char	*s;

	s = "0123456789abcdef";
	i = write(1, "0x", 2);
	i += putwhatever_num(p, s);
	return (i);
}

int	length(long nb)
{
	int	i;

	i = 0;
	if (nb < 9)
		return (i++);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_putint(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i = ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putint(nb / 10);
		ft_putchar(nb % 10 + '0');
	}	
	else
	{
		ft_putchar(nb + '0');
		return (1 + i);
	}
	return (length(nb) + i);
}
