/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:59:26 by rodrodri          #+#    #+#             */
/*   Updated: 2021/11/16 22:10:20 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*m;
	char	*p;

	if (!s || !f)
		return (NULL);
	m = ft_strnew(ft_strlen(s));
	if (!m)
		return (NULL);
	p = m;
	while (*s)
		*m++ = f(*s++);
	return (p);
}
