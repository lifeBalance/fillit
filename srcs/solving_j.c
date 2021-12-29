/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_j.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:54:47 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/29 13:37:56 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h" /* DELETE THIS */
#include "fillit.h"

static void		place_tmino(t_tmino *tmino, uint16_t *bitmap);
static int		try_tmino(t_tmino *tmino, uint16_t *bitmap, size_t size);

void	solve(t_list *tmino_lst, size_t *size)
{
	uint16_t	bitmap[16];
	int			bmap_idx; // 0-255
	int			bmap_row; // 0-15

	ft_bzero(bitmap, sizeof(uint16_t) * 16);
	*size = init_size(tmino_lst);
	printf("Initial size: %zu (tmino count: %zu)\n", *size, ft_lstcount(tmino_lst));
	while (tmino_lst)
	{
		// iterate over the bitmap bits using a unique index
		// that same index is used to set row/col in the tetrimino
		bmap_idx = 0;
		bmap_row = 0;
		while (bmap_idx < WIDTH_UINT16)
		{
			if ((bmap_idx / 5) == 3)
				bmap_row++;
			((t_tmino *)(tmino_lst->content))->col = bmap_idx % 15;
			((t_tmino *)(tmino_lst->content))->row = bmap_row;
			if (try_tmino(((t_tmino *)(tmino_lst->content)), bitmap, *size))
				break ;
			bmap_idx++;
		}
		if (bmap_idx == WIDTH_UINT16)
		{
			(*size)++;
			continue ;
		}
		place_tmino(((t_tmino *)(tmino_lst->content)), bitmap);
		tmino_lst = tmino_lst->next;
	}
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
static int	try_tmino(t_tmino *tmino, uint16_t *bitmap, size_t size)
{
	uint16_t	tmino_bit;
	uint16_t	bmap_bit;
	size_t		tmino_idx;
	size_t		bmap_row;

	tmino_idx = 0;
	bmap_row = tmino->row;
	while (tmino_idx < WIDTH_UINT16)
	{
		tmino_bit = test_bit_pos(tmino->bits, tmino_idx);
		bmap_bit = test_bit_pos(bitmap[bmap_row], tmino->col + (tmino_idx % 4));
		if (tmino_bit && bmap_bit)
			return (0);
		if ((tmino_idx % 4) == 3)
			bmap_row++;
		tmino_idx++;
	}
	if (tmino->col + tmino->width > size)
		return (0);
	if (tmino->row + tmino->height > size)
		return (0);
	return (1);
}

/*
void	javisolve(t_list *tmino_lst, size_t *size)
{
	uint16_t	bitmap[16];
	t_list		*tmp;
	// Initialize the bitmap
	ft_bzero(bitmap, sizeof(uint16_t) * 16);
	// Calculate the initial size
	*size = init_size(tmino_lst);
	ize, ft_lstcount(tmino_lst));

	// Fabricate fake positions for the tetriminos

	// tmp = tmp->next;// select second node
	// TMP->row = 0;	// fake position for second node
	// TMP->col = 1;	// fake position for second node

	// tmp = tmp->next;// select third node
	// TMP->row = 0;	// fake position for third node
	// TMP->col = 0;	// fake position for second node

	// tmp = tmp->next;// select fourth node
	// TMP->row = 0;	// fake position for fourth node
	// TMP->col = 3;	// fake position for fourth node

	// tmp = tmp->next;
	// TMP->row = 3;	// fake position for first node
	// TMP->col = 0;	// fake position for first node
	// try placing a tetrimino before writing to it or the bitmap
	// place the tetriminos on the bitmap
	// use backtracking to re-try tetrimino positioning until all pieces are
	// successfully placed on the bitmap, and the tetriminos contain the right
	// coordinates. Then just print them all!
}
*/
