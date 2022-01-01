/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_cnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:41:03 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/03 18:15:45 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_clst_cnt(t_list *clst)
{
	t_list	*tmp;
	size_t	count;

	if (!clst)
		return (0);
	count = 1;
	tmp = clst->next;
	while (tmp && clst != tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
