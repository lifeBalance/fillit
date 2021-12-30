/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_j.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:32:26 by oabdelfa          #+#    #+#             */
/*   Updated: 2021/12/30 17:03:39 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**init_charmap(size_t size);
static char	**write_charmap(t_list *tmino_lst, char **charmap, size_t size);
static char	**write_tmino(t_tmino *tmino, char	**charmap, size_t size);

/*
** Print the solution to standard output.
*/
void	print_solution(t_list *tmino_lst, size_t size)
{
	size_t	row;
	size_t	col;
	char	**charmap;

	charmap = init_charmap(size);
	charmap = write_charmap(tmino_lst, charmap, size);
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			ft_putchar(charmap[row][col]);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
	ft_free_array((void **)charmap, size);
}

/*
** Iterate through the bits of a tetrimino and write its label
** at the proper row and column of the character map.
*/
static char	**write_tmino(t_tmino *tmino, char	**charmap, size_t size)
{
	uint8_t	tmino_bit_idx;
	uint8_t	row;
	uint8_t	col;

	row = tmino->pos / size;
	col = tmino->pos % size;
	tmino_bit_idx = 0;
	while (tmino_bit_idx < WIDTH_UINT16)
	{
		if (test_bit_pos(tmino->bits, tmino_bit_idx))
			charmap[row][col] = tmino->label;
		if (tmino_bit_idx % WIDTH_NIBBLE == 3)
		{
			row++;
			col = tmino->pos % size;
		}
		else
			col++;
		tmino_bit_idx++;
	}
	return (charmap);
}

/*
** Iterate through the list of tetriminos and write their labels
** at the proper row and column of the character map.
*/
static char	**write_charmap(t_list *tmino_lst, char	**charmap, size_t size)
{
	while (tmino_lst)
	{
		charmap = write_tmino(((t_tmino *)(tmino_lst->content)), charmap, size);
		tmino_lst = tmino_lst->next;
	}
	return (charmap);
}

/*
**	Allocate memory for an array of strings.
**	and set each character to a dot ('.')
*/
static char	**init_charmap(size_t size)
{
	char	**charmap;
	size_t	row;

	charmap = (char **)malloc(size * sizeof(char *));
	if (!charmap)
		ft_bail("error");
	row = 0;
	while (row < size)
	{
		charmap[row] = ft_strnew(size);
		if (!charmap[row])
			ft_bail("error");
		ft_memset(charmap[row], '.', size);
		row++;
	}
	return (charmap);
}
