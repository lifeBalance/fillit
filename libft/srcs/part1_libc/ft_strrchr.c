/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:42:06 by rodrodri          #+#    #+#             */
/*   Updated: 2021/11/05 11:35:55 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	last;

	last = ft_strlen(s);
	while (last >= 0)
	{
		if (s[last] == (char)c)
			return ((char *)(s + last));
		last--;
	}
	return (NULL);
}
/*
** Check this smarty-pants way:
**{
**	size_t	last;
**
**	last = ft_strlen(s) + 1;
**	while (last--)
**		if (s[last] == (char)c)
**			return ((char *)s + last);
**	return (NULL);
**}
*/
