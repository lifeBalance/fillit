/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:54:47 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/01 13:35:39 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h" /* DELETE THIS */
#include "fillit.h"

static void		reset_coord(t_list *node);
static void		write_tmino(t_tmino *tmino, uint16_t *bitmap, size_t size);
static int		place_tmino(t_tmino *tmino, uint16_t *bitmap, size_t size);

void	solve(t_list *head, t_list *tmino_lst, uint16_t *bitmap, size_t *size)
{
	t_tmino		*tmino;

	if (tmino_lst == NULL)
		return ;
	tmino = ((t_tmino *)(tmino_lst->content));
	if (place_tmino(tmino, bitmap, *size))
	{
		write_tmino(tmino, bitmap, *size);
		solve(head, tmino_lst->next, bitmap, size);
	}
	else
	{
		if (tmino->id == 0 && tmino->pos + tmino->height >= *size && tmino->pos + tmino->width >= *size)
		{
			(*size)++;
			ft_lstiter(head, reset_coord); // reset coordinates of all pieces
			tmino_lst = head;
		}
		else
		{
			reset_coord(tmino_lst);  // reset coordinates ONLY of current piece
			tmino_lst = lst_find_id(head, tmino->id - 1); // backtrack
			((t_tmino *)(tmino_lst->content))->pos++;
		}
		ft_bzero(bitmap, sizeof(uint16_t) * 16); // reset map
		solve(head, tmino_lst, bitmap, size);
	}
}

/*
**	Use the tetrimino's 'pos' field, to
**	write the 'bits' field to the bitmap.
*/
static void	write_tmino(t_tmino *tmino, uint16_t *bitmap, size_t size)
{
	size_t		bmap_row;
	size_t		bmap_col;
	size_t		tmino_idx;

	tmino_idx = 0;
	while (tmino_idx < WIDTH_UINT16)
	{
		bmap_row = (tmino->pos / size) + (tmino_idx / WIDTH_NIBBLE);
		bmap_col = (tmino->pos % size) + (tmino_idx % WIDTH_NIBBLE);
		if (test_bit_pos(tmino->bits, tmino_idx))
			bitmap[bmap_row] = set_bit_pos(bitmap[bmap_row], bmap_col);
		tmino_idx++;
	}
}

/*
**	Check if a tetrimino can be placed without any collision (with the bits
**	of other tetriminos or with the bitmap borders) at the coordinates given
**	by the tetrimino's 'pos' field. It keeps updating this position until the
**	tetrimino's is placed.
**	Return '1' if the tetrim. can be placed in the current map; '0' otherwise.
*/
static int	place_tmino(t_tmino *tmino, uint16_t *bitmap, size_t size)
{
	uint16_t	tmino_bit;
	uint16_t	bmap_bit;
	size_t		tmino_idx;

	while (check_height(tmino, size))
	{
		if (!check_width(tmino, size) && tmino->pos == 0)
			return (0);
		tmino_idx = 0;
		while (tmino_idx < WIDTH_UINT16)
		{
			tmino_bit = test_bit_pos(tmino->bits, tmino_idx);
			bmap_bit = test_bit_pos(bitmap[(tmino->pos / size) + \
				(tmino_idx / WIDTH_NIBBLE)], (tmino->pos % size) + \
				(tmino_idx % WIDTH_NIBBLE));
			if (tmino_bit && bmap_bit)
				break ;
			tmino_idx++;
		}
		if ((tmino_idx == WIDTH_UINT16) && check_width(tmino, size))
			return (1);
		tmino->pos++;
	}
	return (0);
}

static void	reset_coord(t_list *node)
{
	((t_tmino *)(node->content))->pos = 0;
}

/*
void	solve(t_list *tmino_lst, size_t *size)
{
	uint16_t	bitmap[16];
	t_list		*tmp;

	// Initialize the bitmap
	ft_bzero(bitmap, sizeof(uint16_t) * 16);

	// Calculate the initial size
	*size = init_size(tmino_lst);

	// Fabricate fake positions for the tetriminos
	// tmp = tmp->next;// select second node
	// ((t_tmino *)(tmp->content))->pos = 2;	// fake position for second node

	// tmp = tmp->next;// select third node
	// ((t_tmino *)(tmp->content))->pos = 4;	// fake position for second node

	// tmp = tmp->next;// select fourth node
	// ((t_tmino *)(tmp->content))->pos = 5;	// fake position for second node
}
*/
