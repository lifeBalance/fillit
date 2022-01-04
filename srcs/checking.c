/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:22:27 by oabdelfa          #+#    #+#             */
/*   Updated: 2022/01/04 14:49:46 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_checkerr(int j, char buf)
{
	if ((j % 5 == 4) && buf != '\n')
		ft_bail("error");
	if (!(j % 5 == 4) && (buf != '#' && buf != '.') && j != 20)
		ft_bail("error");
}

void	ft_bail(char *msg)
{
	ft_putendl(msg);
	exit (EXIT_FAILURE);
}

void	ft_checkargc(int argc)
{
	if (argc != 2)
	{
		ft_putendl("fillit: missing file operand");
		ft_putendl("usage: './fillit <filename>'");
		exit (EXIT_FAILURE);
	}
}

void	ft_checktmino(char	*buf)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (i >= 1 && buf[i - 1] == '#')
				cnt++;
			if (i < 19 && buf[i + 1] == '#')
				cnt++;
			if (i >= 5 && buf[i - 5] == '#')
				cnt++;
			if (i < 15 && buf[i + 5] == '#')
				cnt++;
		}
		i++;
	}
	if (cnt == 6 || cnt == 8)
		return ;
	ft_bail("error");
}

size_t	check_tmino_count(t_list *tmino_lst)
{
	size_t	count;

	count = ft_lstcount(tmino_lst);
	if (count > 0 && count < 27)
		return (1);
	return (0);
}
