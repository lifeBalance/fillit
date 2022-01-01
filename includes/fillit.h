/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:50:56 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/01 12:29:26 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
**	Allowed Headers.
*/
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include "libft.h"

/*
**	Type definitions.
*/
typedef struct s_tmino
{
	uint16_t	bits;
	char		label;
	uint8_t		id;
	uint8_t		pos;
	uint8_t		width;
	uint8_t		height;
}	t_tmino;

/*
**	Macro definitions.
*/
# define TMINO_LEN			21
# define WIDTH_UINT64		64
# define WIDTH_UINT16		16
# define WIDTH_NIBBLE		4
# define TMINO_FIRST_ROW	0xF		/* LSB 1111 0000 0000 0000 MSB */
# define TMINO_FIRST_COL	0x111	/* LSB 1000 1000 1000 1000 MSB */
# define TMINO_LAST_ROW		0xF000	/* LSB 0000 0000 0000 1111 MSB */
# define TMINO_LAST_COL		0x8888	/* LSB 0001 0001 0001 0001 MSB */
# define BITMAP_ROW			0xFFFF	/* LSB 1111 1111 1111 1111 MSB */

/*
**	Function prototypes.
*/
void		ft_checkargc(int argc);
void		ft_readtminos(char *fname, t_list **tmino_lst);
void		ft_checkerr(int j, char buf);
void		ft_bail(char *msg);
void		ft_checktmino(char	*buf);
size_t		check_tmino_count(t_list *tmino_lst);
void		solve(t_list *head, t_list *lst, uint16_t *bitmap, size_t *size);
void		print_solution(t_list *tmino_lst, size_t size);

size_t		init_size(t_list *tmino_lst);
int			check_height(t_tmino *tmino, size_t size);
int			check_width(t_tmino *tmino, size_t size);
t_list		*lst_find_id(t_list *lst, uint8_t id);

uint8_t		test_bit_pos(uint16_t val, uint8_t pos);
uint16_t	set_bit_pos(uint16_t val, uint8_t pos);
uint8_t		test_empty_row(uint16_t value);
uint8_t		test_col_bitmap(uint16_t *value, size_t pos);
uint8_t		test_bit_msk(uint16_t value, uint16_t mask);
uint16_t	msk_grp(uint8_t pos, uint8_t width);
uint16_t	read_grp(uint16_t val, uint8_t pos, uint8_t width);
uint16_t	write_grp(uint16_t val, uint16_t grp, uint8_t pos, uint8_t width);

#endif