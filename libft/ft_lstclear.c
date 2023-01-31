/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 11:30:11 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/01 12:53:27 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{	
	t_list	*next_node;

	while (*lst)
	{
		del((*lst)->content);
		next_node = (*lst)->next;
		free(*lst);
		(*lst) = next_node;
	}
	*lst = NULL;
}
