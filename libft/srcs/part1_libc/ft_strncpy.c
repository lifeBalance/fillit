/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:26:52 by rodrodri          #+#    #+#             */
/*   Updated: 2021/11/12 21:50:54 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	if (ft_strlen(src) < len)
	{
		ft_strcpy(dst, src);
		ft_bzero(dst + ft_strlen(src), len - ft_strlen(src));
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

/*
**Old ways:
**{
**	char	*ret;
**
**	ret = dst;
**	while (*src && len)
**	{
**		*dst++ = *src++;
**		len--;
**	}
**	while (len--)
**		*dst++ = '\0';
**	return (ret);
**}
*/
