/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:41:03 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/06 19:45:37 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clst_add(t_list **clst, t_list *node)
{
	t_list	*tmp;

	if (!clst || !node)
		return ;
	if (!(*clst))
	{
		*clst = node;
		(*clst)->next = *clst;
	}
	else
	{
		tmp = (*clst)->next;
		while (tmp->next != *clst)
			tmp = tmp->next;
		tmp->next = node;
		node->next = *clst;
		*clst = node;
	}
}
