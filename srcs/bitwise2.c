/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:02:23 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/27 16:56:29 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint16_t	read_grp(uint16_t val, uint8_t pos, uint8_t width)
{
	return ((val & msk_grp(pos, width)) >> pos);
}

uint16_t	write_grp(uint16_t val, uint16_t grp, uint8_t pos, uint8_t width)
{
	return ((~msk_grp(width, pos) & val) | (grp << pos));
}
