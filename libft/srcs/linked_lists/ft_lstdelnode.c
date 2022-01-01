/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:41:03 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/02 22:34:11 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelnode(t_list **l, t_list *n, void (*del)(void *c, size_t s))
{
	t_list	*curr;
	t_list	*prev;

	if (!l || !(*l) || !n || !del)
		return ;
	if (*l == n)
	{
		*l = n->next;
		ft_lstdelone(&n, del);
	}
	else
	{
		prev = *l;
		curr = (*l)->next;
		while (curr)
		{
			if (curr == n)
			{
				prev->next = curr->next;
				ft_lstdelone(&n, del);
			}
			prev = curr;
			curr = curr->next;
		}
	}
}
