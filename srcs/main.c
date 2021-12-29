/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:51:19 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/28 19:06:12 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h" /* DELETE THIS */
#include "fillit.h"

int	main(int argc, char **argv)
{
	t_list		*tmino_lst;
	size_t		size;

	tmino_lst = NULL;
	ft_checkargc(argc);
	ft_readtminos(argv[1], &tmino_lst);

	solve(tmino_lst, &size);
	print_solution(tmino_lst, size);
	// printf("Pieces:\n"); // check all pieces along with coordinates and dimensions
	// ft_lstiter(tmino_lst, print_tmino_node);
	return (0);
}
