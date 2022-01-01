/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:50:50 by rodrodri          #+#    #+#             */
/*   Updated: 2021/11/17 00:14:46 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n >= 1 && *s1 && *s2)
	{
		if ((const unsigned char)*s1 != (const unsigned char)*s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return ((int)((const unsigned char)*(s1 - 1) - \
						(const unsigned char)*(s2 - 1)));
	return ((int)((const unsigned char)*s1 - (const unsigned char)*s2));
}
