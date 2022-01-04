/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:51:19 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/04 15:31:59 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tmino	init_tmino(char *buf);
static uint16_t	get_bits(char *buf);
static void		shift_tmino(t_tmino *tmino);
static void		measure_tmino(t_tmino *tmino);

void	ft_readtminos(char *fname, t_list **tmino_lst)
{
	int			fd;
	char		buf[TMINO_LEN];
	int			ret;
	t_list		*node;
	t_tmino		tmino;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		ft_bail("error");
	ret = read(fd, buf, TMINO_LEN);
	while (ret)
	{
		ft_checktmino(buf);
		tmino = init_tmino(buf);
		node = ft_lstnew(&tmino, sizeof(tmino));
		if (!node)
			ft_bail("error");
		ft_lstappend(tmino_lst, node);
		if (ret != TMINO_LEN)
			break ;
		ret = read(fd, buf, TMINO_LEN);
	}
	if (!check_tmino_count(*tmino_lst) || ret != (TMINO_LEN - 1))
		ft_bail("error");
}

/*
** Reads the characters in the 'buf' argument, translate to
** either 1 or 0, write the bits into an uint16_t, and return it.
** (This value will be assigned in the hub function to the 'bits' field).
*/
static uint16_t	get_bits(char *buf)
{
	int			i;
	int			j;
	int			cnt;
	uint16_t	bits;

	i = 0;
	j = 0;
	cnt = 0;
	bits = 0;
	while (j < TMINO_LEN)
	{
		ft_checkerr(j, buf[j]);
		if (buf[j] == '#')
		{
			bits = set_bit_pos(bits, i);
			cnt++;
		}
		if (!(j % 5 == 4))
			i++;
		j++;
	}
	if (cnt != 4)
		ft_bail("error");
	return (bits);
}

/*
** Hub function to give the tetrimino structure the
** initial values for the corresponding struct fields.
*/
static t_tmino	init_tmino(char *buf)
{
	t_tmino			tmino;
	static char		label = 'A';
	static uint8_t	id = 0;

	tmino.bits = get_bits(buf);
	shift_tmino(&tmino);
	measure_tmino(&tmino);
	tmino.pos = 0;
	tmino.label = label;
	tmino.id = id;
	label++;
	id++;
	return (tmino);
}

static void	shift_tmino(t_tmino *tmino)
{
	while (!test_bit_msk(tmino->bits, TMINO_FIRST_ROW))
		(tmino->bits) >>= 4;
	while (!test_bit_msk(tmino->bits, TMINO_FIRST_COL))
		(tmino->bits) >>= 1;
}

/*
** Measure the width and height of a tetrimino and
** store these values in the corresponding struct fields.
*/
static void	measure_tmino(t_tmino *tmino)
{
	uint8_t		offset;
	uint16_t	mask;
	uint8_t		width;
	uint8_t		height;

	width = 4;
	height = 4;
	offset = 12;
	while (read_grp(tmino->bits, offset, 4) == 0)
	{
		height--;
		offset -= 4;
	}
	mask = TMINO_LAST_COL;
	while (test_bit_msk(tmino->bits, mask) == 0)
	{
		width--;
		mask >>= 1;
	}
	tmino->height = height;
	tmino->width = width;
}
