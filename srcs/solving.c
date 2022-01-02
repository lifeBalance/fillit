/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:54:47 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/02 20:15:45 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		reset_coord(t_list *node);
static void		write_tmino(t_tmino *tmino, uint16_t *bitmap, size_t size);
static int		place_tmino(t_tmino *tmino, uint16_t *bitmap, size_t size);
static t_list	*del_tmino(t_list *node, uint16_t *bitmap, size_t size);

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
		if (tmino->id == 0 && tmino->pos >= last_pos(tmino, *size))
		{
			(*size)++;
			ft_lstiter(head, reset_coord);
			tmino_lst = head;
			ft_bzero(bitmap, sizeof(uint16_t) * 16);
		}
		else
		{
			reset_coord(tmino_lst);
			tmino_lst = del_tmino(lst_find_id(head, tmino->id - 1), bitmap, *size);
			(((t_tmino *)(tmino_lst->content))->pos)++;
		}
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

static t_list	*del_tmino(t_list *node, uint16_t *bitmap, size_t size)
{
	size_t		bmap_row;
	size_t		bmap_col;
	size_t		tmino_idx;
	t_tmino		*tmino;

	tmino_idx = 0;
	tmino = (t_tmino *)(node->content);
	while (tmino_idx < WIDTH_UINT16)
	{
		bmap_row = (tmino->pos / size) + (tmino_idx / WIDTH_NIBBLE);
		bmap_col = (tmino->pos % size) + (tmino_idx % WIDTH_NIBBLE);
		if (test_bit_pos(tmino->bits, tmino_idx))
			bitmap[bmap_row] = clear_bit_pos(bitmap[bmap_row], bmap_col);
		tmino_idx++;
	}
	return (node);
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

	while (tmino->pos <= last_pos(tmino, size))
	{
		if (!check_right_side(tmino, size))
			tmino->pos = ((tmino->pos / size) + 1) * size;
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
		if (tmino_idx == WIDTH_UINT16)
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
void	solve(t_list *head, t_list *tmino_lst, uint16_t *bitmap, size_t *size)
{
	t_tmino		*tmino;
	(void)head;
	*size = 6;
	printf("initial size: %zu (%zu pieces)\n", *size, ft_lstcount(head));
	while (tmino_lst)
	{
		tmino = ((t_tmino *)(tmino_lst->content));
		printf("%c's last position: %d\n", tmino->label, last_pos(tmino, *size));
		if (place_tmino(tmino, bitmap, *size))
		{
			printf("%c was placed at %d\n", tmino->label, tmino->pos);
			write_tmino(tmino, bitmap, *size);
		}
		else
		{
			printf("%c couldn't be placed at %hhu\n", tmino->label, tmino->pos);
			(*size)++;
			reset_coord(tmino_lst);
			printf("increasing size to %zu\n", *size);
			continue ;
		}
		tmino_lst = tmino_lst->next;
	}
}
	// printf("size: %zu (%zu pieces)\n", *size, ft_lstcount(head));
		// printf("%c was placed at %d\n", tmino->label, tmino->pos);
			// printf("%c couldn't be placed at %d\n", tmino->label, tmino->pos);
			// printf("%c requests increase the size to %zu\n", tmino->label, *size);
			// printf("backtracking to %c; now at %d position\n",
*/
