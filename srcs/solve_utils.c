/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:54:47 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/06 17:38:51 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	find_integral_sqrt(size_t num);

/*
**	Returns the last possible position of a tetrimino before it collides
**	with any of the borders; if the return value is negative, the caller
**	would know that the size is not big enough to accomodate the piece.
*/
int	last_pos(t_tmino *tmino, size_t size)
{
	return ((size * size) - (tmino->height * size) + (size - tmino->width));
}

/*
**	Returns '0' if a tetrimino at a given position and size collides
**	with the right border; '1' otherwise.
*/
int	check_right_side(t_tmino *tmino, size_t size)
{
	if ((tmino->pos % size) <= (size - tmino->width))
		return (1);
	return (0);
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
