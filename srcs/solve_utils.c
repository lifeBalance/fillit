/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:54:47 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/28 16:46:12 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	find_integral_sqrt(size_t num);

/*
**	Find the initial size of the assembled tetriminos on the bitmap,
**	based on the square root of number of tetriminos, times four (4 because
**	each tetrimino is made up of four '#' blocks).
*/
size_t	init_size(t_list *tmino_lst)
{
	size_t	tminos_count;
	size_t	ret;
		
	tminos_count = ft_lstcount(tmino_lst);
	ret = find_integral_sqrt(tminos_count * 4);
	if (ret * ret < tminos_count * 4)
		return (ret + 1);
	else
		return (ret);
}

/*
**	Find the integral value of the square root of a positive integer.
*/
static size_t	find_integral_sqrt(size_t num)
{
	size_t	ret;

	ret = 1;
	while (1)
	{
		if (ret * ret == num)
			return (ret);
		else if (ret * ret > num)
		{
			--ret;
			break ;
		}
		ret++;
	}
	return (ret);
}
