/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:50:56 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/23 13:24:14 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

/*
**	Allowed Headers.
*/
# define FILLIT_H
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
	uint8_t		col;
	uint8_t		row;
	uint16_t	bits;
	char		label;
}	t_tmino;


/*
**	Macro definitions.
*/
# define TMINO_LEN		21
# define WIDTH_UINT64	64
# define WIDTH_UINT16	16
# define WIDTH_NIBBLE	4
# define FIRST_ROW		61440	/* 1111 0000 0000 0000 */
# define FIRST_COL		34952	/* 1000 1000 1000 1000 */
# define TMINO			((t_tmino *)(tmino_lst->content))

/*
**	Function prototypes.
*/
void		ft_checkargc(int argc);
void		ft_readtminos(char *fname, t_list **tmino_lst);
t_tmino		ft_buildtmino(char *buf);
uint16_t	ft_bits(char *buf);
uint16_t	set_bit(uint8_t pos, uint16_t val);
uint8_t		test_bit(uint8_t pos, uint16_t val);
uint8_t		test_first_row(uint16_t value);
uint8_t		test_first_col(uint16_t value);
char		*nibblify(uint16_t n);
void		print_tmino(t_tmino *tmino);
void		ft_checkerr(int j, char buf);
void		ft_bail(char *msg);
void		print_tmino_node(t_list *n);
void		ft_checktmino(char	*buf);
void		ft_shift_tmino(t_tmino *tmino);
void		ft_measure_tmino(t_tmino *tmino);
void		fakesolve(t_list *tmino_lst, size_t *charmap_dim, uint16_t *bitmap);
void		print_solution(uint16_t *bitmap, size_t dimensions);
uint8_t		test_empty_row(uint16_t value);
uint8_t		test_empty_col(uint16_t *value, size_t pos);

#endif