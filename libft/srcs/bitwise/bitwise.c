/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 00:48:12 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/18 18:11:50 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitwise.h"

uint16_t	create_mask(uint8_t offset)
{
	return (1 << offset);
}

uint16_t	test_bit(uint8_t pos, uint16_t val)
{
	return ((val & 1 << pos) > 0);
}

uint16_t	set_bit(uint8_t pos, uint16_t val)
{
	return (val | 1 << pos);
}

uint16_t	clear_bit(uint8_t pos, uint16_t val)
{
	return (val & ~(1 << pos));
}

uint16_t	toggle_bit(uint8_t pos, uint16_t val)
{
	return (val ^ (1 << pos));
}

uint16_t	msk_grp(uint8_t width, uint8_t pos)
{
	uint16_t mask;

	if (width == 0)
		return (0);
	mask = 1;
	while (--width)
	{
		mask <<= 1;
		mask |= 1;
	}
	mask <<= pos;
	return (mask);
}

uint16_t	read_grp(uint8_t pos, uint8_t width, uint16_t val)
{
	return ((val & msk_grp(pos, width)) >> pos);
}

uint16_t	write_grp(uint8_t pos, uint8_t width, uint16_t val, uint16_t grp)
{
	return ((~msk_grp(width, pos) & val) | (grp << pos));
}
