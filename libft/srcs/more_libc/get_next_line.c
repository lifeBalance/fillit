/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:00:34 by rodrodri          #+#    #+#             */
/*   Updated: 2021/12/06 19:40:18 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		set_buf(int fd, t_list **b);
static int		read_ln(int fd, t_list *b);
static int		build_ln(char **ln, t_list *b);
static t_bfd	init_bfd(int fd);

int	get_next_line(const int fd, char **ln)
{
	static t_list	*b = NULL;
	int				ret;

	if (fd < 0 || fd == 1 || fd == 2 || !ln || set_buf(fd, &b) < 0)
		return (-1);
	ret = read_ln(fd, b);
	if (ret == 0)
	{
		ft_clst_del(&b, ft_lstdelcont);
		return (0);
	}
	if (ret < 0 || build_ln(ln, b) < 0)
	{
		while (b)
			ft_clst_del(&b, ft_lstdelcont);
		return (-1);
	}
	return (1);
}

static int	read_ln(int fd, t_list *b)
{
	t_list	*ln_node;
	ssize_t	ret;
	char	*buf;

	buf = ((t_bfd *)(b->content))->bf;
	ret = read(fd, buf + ft_strlen(buf), BUFF_SIZE - ft_strlen(buf));
	if (ret == 0 && ft_strlen(buf) == 0)
		return (0);
	while (ft_strlen(buf) == BUFF_SIZE && !ft_strchr(buf, '\n') && ret > 0)
	{
		((t_bfd *)(b->content))->len += BUFF_SIZE;
		ln_node = ft_lstnew(buf, BUFF_SIZE + 1);
		if (!ln_node)
			return (-1);
		ft_lstappend(&(((t_bfd *)(b->content))->lst), ln_node);
		ft_strclr(buf);
		ret = read(fd, buf, BUFF_SIZE);
	}
	if (ret < 0)
		return (-1);
	return (1);
}

static int	build_ln(char **ln, t_list *b)
{
	t_list	*tmp_lst;
	size_t	b_len;
	char	*buf;

	buf = ((t_bfd *)(b->content))->bf;
	b_len = 0;
	if (ft_strchr(buf, '\n'))
		b_len = ft_strchr(buf, '\n') - buf;
	else if (ft_strlen(buf) < BUFF_SIZE)
		b_len = ft_strlen(buf);
	*ln = ft_strnew(((t_bfd *)(b->content))->len + b_len);
	if (!(*ln))
		return (-1);
	tmp_lst = ((t_bfd *)(b->content))->lst;
	while (tmp_lst)
	{
		ft_strcat(*ln, tmp_lst->content);
		tmp_lst = tmp_lst->next;
	}
	if (((t_bfd *)(b->content))->lst)
		ft_lstdel(&((t_bfd *)(b->content))->lst, ft_lstdelcont);
	ft_strncat(*ln, buf, b_len);
	ft_memmove(buf, buf + (b_len + 1), BUFF_SIZE - (b_len + 1));
	ft_strclr(buf + BUFF_SIZE - (b_len + 1));
	return (0);
}

static int	set_buf(int fd, t_list **b)
{
	t_list	*tmp_node;
	t_list	*start;
	t_bfd	tmp_cont;

	start = *b;
	while (*b && ((t_bfd *)((*b)->content))->fd != fd)
	{
		(*b) = (*b)->next;
		if ((*b) == start || ((t_bfd *)((*b)->content))->fd == fd)
			break ;
	}
	if (*b == NULL || ((t_bfd *)((*b)->content))->fd != fd)
	{
		tmp_cont = init_bfd(fd);
		tmp_node = ft_lstnew(&tmp_cont, sizeof(tmp_cont));
		if (!tmp_node)
			return (-1);
		ft_clst_add(b, tmp_node);
	}
	return (0);
}

static t_bfd	init_bfd(int fd)
{
	return ((t_bfd){"", fd, NULL, 0});
}

/*
** Find out why I have to use init_bfd to initialize the structure, instead
** of:
**		ft_strclr(tmp_cont.bf);
**		tmp_cont.fd = fd;
**		tmp_cont.lst = NULL;
**		tmp_cont.len = 0;
** A designated initializer also works (but the Norm forbids their use):
**		t_bfd	tmp_cont = {"", fd, NULL, 0};
*/