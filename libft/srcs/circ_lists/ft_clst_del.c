/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:41:03 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/03 22:11:37 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clst_del(t_list **clst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*nxt;
	size_t	count;

	if (!clst || !(*clst) || !del)
		return ;
	count = ft_clst_cnt(*clst);
	if (count == 1)
		ft_lstdelone(clst, del);
	else
	{
		tmp = *clst;
		nxt = (*clst)->next;
		while (count > 1)
		{
			tmp = tmp->next;
			count--;
		}
		tmp->next = nxt;
		ft_lstdelone(clst, del);
		*clst = nxt;
	}
}
