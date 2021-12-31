/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:41:03 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/31 20:10:53 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

static size_t	max(size_t a, size_t b);

char	*nibblify(uint16_t n)
{
	size_t	mask;
	size_t	bits;
	int		len;
	char	*s;

	bits = sizeof(n) * 8;
	len = bits + (bits / 4) - 1;
	s = ft_strnew(len);
	if (!s)
		return (NULL);
	mask = 1;
	len--;
	while (len >= 0)
	{
		if (len % 5 == 4)
			s[len--] = ' ';
		s[len--] = ((n & mask) > 0) + '0';
		mask <<= 1;
	}
	return (s);
}

/*
** Measure solution of bit map, and print what you need.
*/
void	print_bitmap(uint16_t *bitmap, size_t dimensions)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (row < min(dimensions, WIDTH_UINT16))
	{
		col = 0;
		while (col < min(dimensions, WIDTH_UINT16))
		{
			if (test_bit_pos(bitmap[row], col))
				ft_putchar('#');
			else
				ft_putchar('.');
			if (col == min(dimensions, WIDTH_UINT16) - 1)
				ft_putchar('\n');
			col++;
		}
		row++;
	}
}

void	print_tmino(t_tmino *tmino)
{
	int	i;

	printf("id: %hhu, pos: %hhu, ", tmino->id, tmino->pos);
	printf("width: %hhu, height: %hhu\n", tmino->width, tmino->height);
	i = 0;
	while (i < WIDTH_UINT16)
	{
		if (test_bit_pos(tmino->bits, i))
			ft_putchar(tmino->label);
		else
			ft_putchar('.');
		if (i % 4 == 3)
			ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

void	print_tmino_node(t_list *n)
{
	print_tmino(((t_tmino *)(n->content)));
}

size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

/*
**	1. Scan rows find width of the bitmap
**	2. Scan cols find height of the bitmap
**	3. Return the size using as the max(width, height).
*/
size_t calculate_size(uint16_t *bitmap)
{
	size_t width;
	size_t height;
	size_t i;

	width = WIDTH_UINT16;
	height = WIDTH_UINT16;
	i = WIDTH_UINT16 - 1;
	while(bitmap[i] == 0)
	{
		height--;
		i--;
	}
	i = WIDTH_UINT16 - 1;
	while(test_col_bitmap(bitmap, i))
	{
		width--;
		i--;
	}
	return (max(width, height));
}

static size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}
