/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:50:56 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/28 16:45:41 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H

# define DEBUG_H

# include "libft.h"
# include "fillit.h"
# include <stdio.h>
# include <stdint.h>

/*
**	Function prototypes.
*/
char		*nibblify(uint16_t n);
void		print_tmino(t_tmino *tmino);
void		print_tmino_node(t_list *n);
void		print_bitmap(uint16_t *bitmap, size_t dimensions);
size_t		min(size_t a, size_t b);
size_t		calculate_size(uint16_t *bitmap);

#endif