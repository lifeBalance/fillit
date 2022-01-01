/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:54:47 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/02 00:46:54 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h" /* DELETE THIS */
#include "fillit.h"

static void		reset_coord(t_list *node);
static void		write_tmino(t_tmino *tmino, uint16_t *bitmap, size_t size);
static int		place_tmino(t_tmino *tmino, uint16_t *bitmap, size_t size);
// /*
void	solve(t_list *head, t_list *tmino_lst, uint16_t *bitmap, size_t *size)
{
	t_tmino		*tmino;

	// printf("size: %zu (%zu pieces)\n", *size, ft_lstcount(head));
	if (tmino_lst == NULL)
		return ;
	tmino = ((t_tmino *)(tmino_lst->content));
	if (place_tmino(tmino, bitmap, *size))
	{
		// printf("%c was placed at %d\n", tmino->label, tmino->pos);
		write_tmino(tmino, bitmap, *size);
		solve(head, tmino_lst->next, bitmap, size);
	}
	else
	{
		// printf("%c couldn't be placed at %d\n", tmino->label, tmino->pos);
		if (tmino->id == 0 && tmino->pos >= last_pos(tmino, *size))
		{
			(*size)++;
			// printf("%c requests increase the size to %zu\n", tmino->label, *size);
			ft_lstiter(head, reset_coord); // reset coordinates of all pieces
		}
		else
		{
			reset_coord(tmino_lst);  // reset coordinates ONLY of current piece
			tmino_lst = lst_find_id(head, tmino->id - 1); // backtrack to piece before
			(((t_tmino *)(tmino_lst->content))->pos)++; // increase its position
			printf("backtracking to %c; now at %d position\n", 
				((t_tmino *)(tmino_lst->content))->label,
				((t_tmino *)(tmino_lst->content))->pos);
		}
		tmino_lst = head; // rewind the list
		ft_bzero(bitmap, sizeof(uint16_t) * 16); // reset map
		solve(head, tmino_lst, bitmap, size);
	}
}
// */
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

	while (tmino->pos <= last_pos(tmino, size))
	{
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
		if (tmino_idx == WIDTH_UINT16 && check_width(tmino, size))
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
**	Finds a tetrimino by its 'id' field. It takes 2 arguments:
**	- The head of a linked-list.
**	- The 'id' of the node we want.
**	Returns the address of the node; 'NULL' if it doesn't exist.
*/
t_list	*lst_find_id(t_list *lst, uint8_t id)
{
	while (lst)
	{
		if (((t_tmino *)(lst->content))->id == id)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
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
*/
