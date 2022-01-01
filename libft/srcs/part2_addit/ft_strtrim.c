/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:41:03 by rodrodri          #+#    #+#             */
/*   Updated: 2021/11/15 10:59:44 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspacey(int c);

char	*ft_strtrim(char const *s)
{
	size_t	last;
	size_t	first;
	char	*trimmed;

	if (!s)
		return (NULL);
	first = 0;
	while (ft_isspacey(s[first]))
		first++;
	last = ft_strlen(s) - 1;
	while (ft_isspacey(s[last]) && last >= first)
		last--;
	trimmed = ft_strsub(s, first, last - first + 1);
	if (!trimmed)
		return (NULL);
	return (trimmed);
}

static int	ft_isspacey(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}
