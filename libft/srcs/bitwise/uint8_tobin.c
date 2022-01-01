/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint8_tobin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:41:03 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/18 18:10:06 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"

/*
**	Receives a 'uint8_t' as only argument.
**	Allocates space in the heap for a binary string and builds it,
**	adding space between each group of 4 characters (nibbles).
**	Returns the resulting string.
*/
char	*uint8_tobin(uint8_t n, uint8_t nibblify)
{
	uint8_t	mask;
	int8_t		len;
	char		*s;

	len = sizeof(n) * 8;
	if (nibblify)
		len += (len / 4) - 1;
	s = ft_strnew(len);
	if (!s)
		return (NULL);
	mask = 1;
	len--;
	while (len >= 0)
	{
		if (len % 5 == 4 && nibblify)
			s[len--] = ' ';
		s[len--] = ((n & mask) > 0) + '0';
		mask <<= 1;
	}
	return (s);
}
