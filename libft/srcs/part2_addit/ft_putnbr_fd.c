/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:38:52 by rodrodri          #+#    #+#             */
/*   Updated: 2021/11/14 19:58:45 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		positions;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2", fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	positions = 1;
	while (n / positions >= 10)
		positions *= 10;
	while (positions >= 1)
	{
		ft_putchar_fd((n / positions) % 10 + '0', fd);
		positions /= 10;
	}
}

/* It would have been nice... (if malloc were allowed)
**{
**	char	*s;
**
**	s = ft_itoa(n);
**	if (s)
**	{
**		ft_putstr_fd(s, fd);
**		ft_strdel(&s);
**	}
**}
*/
