/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint16_tobin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:41:03 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/18 23:12:16 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"

/*
**	Allocates space in the heap for a binary string and builds it,
**	based in the value of 'n'.
**	When the 'nibblify' argument is non-zero, bits are grouped into nibbles.
**	Returns the resulting string.
*/
char	*uint16_tobin(uint16_t n, uint8_t nibblify)
{
	uint16_t	mask;
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
