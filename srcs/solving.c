/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:54:47 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/28 19:15:27 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h" /* DELETE THIS */
#include "fillit.h"
#define TMP	((t_tmino *)(tmp->content)) // Forbidden macro!!

static void		place_tmino(t_tmino *tmino, uint16_t *bitmap);
static int		try_tmino(t_tmino *tmino, uint8_t row, uint8_t col, uint16_t *bitmap, size_t size);

/* Bro, plz don't change any of the functions above (they work or almost do... try it out with eval_tests/printing_test.txt)
Play as much as you want in omarsolve, just wire it up in main. If you need extra functions add
them, and comment the ones above ;-)
*/
void	omarsolve(t_list *tmino_lst, size_t *size) // added to fillit.h (for Omar's experiments)
{
	(void)tmino_lst;
	(void)size;
}

void	javisolve(t_list *tmino_lst, size_t *size) //fake solve fn (for printing experiments)
{
	uint16_t	bitmap[16];
	int			ret; // use return values to check WTF is going on

	ft_bzero(bitmap, sizeof(uint16_t) * 16);
	*size = init_size(tmino_lst);
	printf("Initial size: %zu (tmino count: %zu)\n", *size, ft_lstcount(tmino_lst));
	while (tmino_lst)
	{
		ret = try_tmino(((t_tmino *)(tmino_lst->content)), ((t_tmino *)(tmino_lst->content))->row,
		((t_tmino *)(tmino_lst->content))->col, bitmap, *size);
		printf("ret: %d\n", ret);
		while (ret < 1)
		{
			ret = try_tmino(((t_tmino *)(tmino_lst->content)), ((t_tmino *)(tmino_lst->content))->row,
			((t_tmino *)(tmino_lst->content))->col, bitmap, *size);
			
			if (ret == -1)
			
			((t_tmino *)(tmino_lst->content))->col++;
			((t_tmino *)(tmino_lst->content))->row++;
			if (ret == 0)
				(*size)++;
		}
		place_tmino(((t_tmino *)(tmino_lst->content)), bitmap);
		tmino_lst = tmino_lst->next;
	}
	// Recalculate the size after placing the pieces on the bitmap.
	// *size = calculate_size(bitmap);
	printf("New size: %zu\n", *size);
}

/*
**	Use the tetrimino's 'row' and 'col' fields, to
**	write the 'bits' field to the bitmap.
*/
static void	place_tmino(t_tmino *tmino, uint16_t *bitmap)
{
	uint16_t	group;
	size_t		tmino_row;
	size_t		bmap_row;

	tmino_row = 0;
	bmap_row = tmino->row;
	while (tmino_row < WIDTH_UINT16)
	{
		group = read_grp(tmino->bits, tmino_row, WIDTH_NIBBLE);
		bitmap[bmap_row] = write_grp(bitmap[bmap_row], group, tmino->col, WIDTH_NIBBLE);
		tmino_row += 4;
		bmap_row++;
	}
}

/*
**	Check if a tetrimino can be placed without any collision (with the bits
**	of other tetriminos or with the bitmap borders) at the coordinates given
**	by the 'row' and 'col' arguments.
**	Return '0' if the tetrimino can be placed; '1' otherwise.
*/
static int	try_tmino(t_tmino *tmino, uint8_t row, uint8_t col, uint16_t *bitmap, size_t size)
{
	uint16_t	tmino_bit;
	uint16_t	bmap_bit;
	size_t		tmino_idx;
	size_t		bmap_row;

	tmino_idx = 1;
	bmap_row = row;
	while (bmap_row < (row + WIDTH_NIBBLE))
	{
		while (tmino_idx % 5 != 0)
		{
			tmino_bit = test_bit_pos(tmino->bits, tmino_idx - 1);
			bmap_bit = test_bit_pos(bitmap[bmap_row],
				col + ((tmino_idx - 1) % 4));
			if (tmino_bit && bmap_bit)
				return (-1);
			tmino_idx++;
		}
		bmap_row++;
	}
	if (col + tmino->width > size)
		return (0);
	if (row + tmino->height > size)
		return (0);
	return (1);
}
