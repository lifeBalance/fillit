# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 11:09:58 by rodrodri          #+#    #+#              #
#    Updated: 2021/12/24 01:01:07 by rodrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	clang

CFLAGS	=	-Wall -Werror -Wextra -Iincludes

PART1_LIBC	=	ft_memset	ft_bzero	ft_memcpy	ft_memccpy	ft_memmove	\
				ft_memchr	ft_memcmp	ft_strlen	ft_strdup	ft_strcpy	\
				ft_strncpy	ft_strcat	ft_strncat	ft_strlcat	ft_strchr	\
				ft_strrchr	ft_strstr	ft_strnstr	ft_strcmp	ft_strncmp	\
				ft_atoi		ft_isalpha	ft_isdigit	ft_isalnum	ft_isascii	\
				ft_isprint	ft_toupper	ft_tolower

PART2_ADDIT	=	ft_memalloc		ft_memdel		ft_strnew		ft_strdel	\
				ft_strclr		ft_striter		ft_striteri		ft_strmap	\
				ft_strmapi		ft_strequ		ft_strnequ		ft_strsub	\
				ft_strjoin		ft_strtrim		ft_strsplit		ft_itoa		\
				ft_putchar		ft_putstr		ft_putendl		ft_putnbr	\
				ft_putchar_fd	ft_putstr_fd	ft_putendl_fd	ft_putnbr_fd

BONUS_LISTS	=	ft_lstnew		ft_lstdelone	ft_lstdel		ft_lstadd	\
				ft_lstiter		ft_lstmap

EXTRA_BONUS	=	ft_strrev		ft_isspace

MORE_LISTS	=	ft_lstprepend	ft_lstappend	ft_lstcount		ft_lstdelnode\
				ft_lstdelcont

CIRC_LISTS	=	ft_clst_add		ft_clst_del		ft_clst_cnt		ft_clst_iter

BITWISE		=	bitwise		uint8_tobin		uint16_tobin

MORE_LIBC	=	get_next_line

SRCS	=	$(patsubst %, srcs/part1_libc/%, $(addsuffix .c, $(PART1_LIBC)))
SRCS	+=	$(patsubst %, srcs/part2_addit/%, $(addsuffix .c, $(PART2_ADDIT)))
SRCS	+=	$(patsubst %, srcs/linked_lists/%, $(addsuffix .c, $(BONUS_LISTS)))
SRCS	+=	$(patsubst %, srcs/linked_lists/%, $(addsuffix .c, $(MORE_LISTS)))
SRCS	+=	$(patsubst %, srcs/circ_lists/%, $(addsuffix .c, $(CIRC_LISTS)))
SRCS	+=	$(patsubst %, srcs/extra_bonus/%, $(addsuffix .c, $(EXTRA_BONUS)))
SRCS	+=	$(patsubst %, srcs/bitwise/%, $(addsuffix .c, $(BITWISE)))
SRCS	+=	$(patsubst %, srcs/more_libc/%, $(addsuffix .c, $(MORE_LIBC)))

OBJS	=	$(patsubst %.c,%.o,$(notdir $(SRCS)))

.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJS):	$(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -c

clean:
	@/bin/rm -f $(OBJS)

fclean:	clean
	@/bin/rm -f $(NAME)

re:	fclean all
