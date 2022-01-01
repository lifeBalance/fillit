/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:51:19 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/01 20:37:58 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h" /* DELETE THIS */
#include "fillit.h"

int	main(int argc, char **argv)
{
	t_list		*tmino_lst;
	uint16_t	bitmap[16];
	size_t		size;

	tmino_lst = NULL;
	ft_bzero(bitmap, sizeof(uint16_t) * 16);
	ft_checkargc(argc);
	ft_readtminos(argv[1], &tmino_lst);
	size = init_size(tmino_lst);
	// ft_lstiter(tmino_lst, print_tmino_node);
	solve(tmino_lst, tmino_lst, bitmap, &size);
	print_solution(tmino_lst, size);
	ft_lstdel(&tmino_lst, ft_lstdelcont);
	return (0);
}
