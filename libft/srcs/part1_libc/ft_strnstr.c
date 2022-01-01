/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:41:03 by rodrodri          #+#    #+#             */
/*   Updated: 2021/11/12 13:41:08 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*substr;
	char	*ret;
	char	*sub;

	substr = ft_strsub(haystack, 0, len);
	sub = ft_strstr(substr, needle);
	if (sub)
	{
		ret = ft_strstr(haystack, sub);
		ft_strdel(&substr);
		return (ret);
	}
	return (NULL);
}
