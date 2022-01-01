/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:41:03 by rodrodri          #+#    #+#             */
/*   Updated: 2021/11/14 23:07:17 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		return (ft_strcmp(s1, s2) == 0);
	return (0);
}

/*
** You dissapoint me, child...
**{
**	int	i;
**
**	i = 0;
**	while (s1[i])
**	{
**		if (s1[i] != s2[i])
**			return (0);
**		i++;
**	}
**	if (s1[i] == s2[i])
**		return (1);
**	else
**		return (0);
**}
**
** Still not good nuff:
**{
**	if (ft_strcmp(s1, s2) == 0)
**		return (1);*
**	return (0);*
**}
*/
