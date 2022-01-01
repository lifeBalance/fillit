/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:50:50 by rodrodri          #+#    #+#             */
/*   Updated: 2021/11/17 00:00:16 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (const unsigned char)*s1 == (const unsigned char)*s2)
	{
		s1++;
		s2++;
	}
	return ((int)((const unsigned char)*s1 - (const unsigned char)*s2));
}
