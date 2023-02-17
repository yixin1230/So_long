/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 09:52:06 by yizhang       #+#    #+#                 */
/*   Updated: 2022/12/08 15:03:08 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(unsigned int c);
int	ft_putstr(char *s);
int	ft_putptr(uintptr_t p);
int	ft_putint(long nb);
int	length(long nb);
int	putwhatever_num(uintptr_t p, char *s);

#endif
