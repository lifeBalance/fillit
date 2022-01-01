/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:11:19 by rodrodri          #+#    #+#             */
/*   Updated: 2021/11/11 22:10:40 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	return (ft_strchr(str, 0) - str);
}

/*
** You dissapoint me, child...
**{
**	size_t	i;
**
**	i = 0;
**	while (str[i])
**		i++;
**	return (i);
**}
*/
