/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 19:56:59 by yizhang       #+#    #+#                 */
/*   Updated: 2022/10/31 17:17:18 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_str(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}

static	size_t	count_str_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s == c)
		s++;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

static void	free_error(char **p, size_t nb)
{
	size_t	i;

	i = 0;
	while (i <= nb)
	{
		free (p[i]);
		i++;
	}
	free (p);
}

static char	**ft_cpy(const char *s, char **p, char c, size_t nb)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	s_len;

	i = 0;
	j = 0;
	s_len = ft_strlen(s);
	while (j < nb)
	{
		while (s[i] == c && i < s_len)
			i++;
		len = count_str_len(&s[i], c);
		p[j] = ft_substr(s, i, len);
		if (!p[j])
		{
			free_error(p, nb);
			return (NULL);
		}
		i += len;
		j++;
	}
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	nb;

	if (!s)
		return (NULL);
	nb = count_str(s, c);
	p = ft_calloc(nb + 1, sizeof(char *));
	if (!p)
		return (NULL);
	p = ft_cpy(s, p, c, nb);
	return (p);
}
