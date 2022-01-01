/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:42:06 by rodrodri          #+#    #+#             */
/*   Updated: 2021/11/10 23:24:25 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	ft_memcpy(s1 + len_s1, s2, ft_strlen(s2));
	ft_bzero(s1 + len_s1 + ft_strlen(s2), 1);
	return (s1);
}

/*
** The way of the noob:
**{
**	char	*ret;
**
**	ret = s1;
**	while (*s1)
**		s1++;
**	while (*s2)
**		*s1++ = *s2++;
**	*s1 = '\0';
**	return (ret);
**}
*/
