/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:00:56 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/24 00:21:51 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** Macro Definitions.
*/
# define BUFF_SIZE 5

/*
** Nested Headers.
*/
# include "libft.h"

/*
** Function Prototypes.
*/
int		get_next_line(const int fd, char **line);

/*
** Type definitions.
*/
typedef struct s_bfd
{
	char	bf[BUFF_SIZE + 1];
	int		fd;
	t_list	*lst;
	size_t	len;
}	t_bfd;

#endif
