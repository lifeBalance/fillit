/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:26:52 by rodrodri          #+#    #+#             */
/*   Updated: 2021/11/10 21:55:16 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	ft_memcpy(dst, src, ft_strlen(src));
	ft_bzero(dst + ft_strlen(src), 1);
	return (dst);
}

/*
**  The old basecamp way, when we couln't reuse code...
**{
**	int	i;
**
**	i = 0;
**	while (src[i])
**	{
**		dst[i] = src[i];
**		i++;
**	}
**	dst[i] = src[i];
**	return (dst);
**}	
*/
